.. default-role:: token

.. _aoc:

Aspect-Oriented C
=================

.. _intro:

Introduction
------------

This section presents an aspect-oriented extension of the C programming language (hereinafter
:abbr:`AOC (Aspect-Oriented C)`).
This extension allows you to extract cross-cutting concerns of programs into separate modules, so-called
:ref:`aspects <aspects>`, consisting of a set of :ref:`advices <advices>` primarily.

You can implement cross-cutting concerns within :ref:`advice bodies <advice_bodies>` using any correct C code suitable
for function bodies.
Also, you can use `GCC <https://gcc.gnu.org/>`__ compiler extensions and a set of
:ref:`special directives <special_directives>`.
:ref:`Advices <advices>` include :ref:`pointucts <pointcuts>` to specify *join points* of the program for which it is
necessary to execute this code.
For instance, AOC deals with definitions and substitutions of macros as well as definitions and declarations of
functions, variables, and composite types as join points.
In order to simplify the development of aspects, macros and declarations of functions, variables, and types used to
describe join points generally coincide in syntax, constraints, and semantics with the corresponding constructions of
the C programming language with GCC compiler extensions (see sections :ref:`macros` and :ref:`decls` for details).
You can see an example of an aspect in :numref:`aspect-sample`.

.. code-block:: c
    :caption: Example of an aspect with two advices
    :name: aspect-sample

    before: call(void lock(void))
    {
        if (locks_counter)
            abort();
        locks_counter++;
    }

    before: call(void unlock(void))
    {
        if (!locks_counter)
            abort();
        locks_counter--;
    }

Before parsing aspects, *aspect preprocessing* is carried out.
Aspect preprocessing behaves exactly in the same way as preprocessing performed by the `GCC <https://gcc.gnu.org/>`__
compiler except for symbol **@** is treated instead of **#**.
:numref:`aspect-macros-and-conditionals` exemplifies using such preprocessor directives as macros and conditionals in
the aspect.
The corresponding preprocessed aspect is shown in :numref:`preprocessed-aspect`.

.. code-block:: c
    :caption: Example of using preprocessor macros and conditionals in an aspect
    :name: aspect-macros-and-conditionals
    :force:

    @define LOG_FILE "work/info.txt"
    @define GET get_property

    @if defined DEBUG
    @define LOG(action, prop) $fprintf<LOG_FILE, "%s property %s\n", action, prop>
    @else
    @define LOG(action, prop)
    @endif

    query: call(int GET(const char *))
    {
        LOG("get", $arg_sign1);
    }

.. code-block:: c
    :caption: Preprocessed aspect
    :name: preprocessed-aspect

    # 10 "aspect-macros-and-conditionals.aspect"
    query: call(int get_property(const char *))
    {
      $fprintf<"work/info.txt", "%s property %s\n", "get", $arg_sign1>;
    }

In addition to using preprocessor macros and conditionals in aspects, you can also include aspects like C source files
include headers.
:numref:`aspect-include` demonstrates an example of using **@include** in the aspect.
The included aspect is shown above in :numref:`aspect-macros-and-conditionals`.
The corresponding preprocessed aspect is shown in :numref:`preprocessed-aspect-2`.

.. code-block:: c
    :caption: Example of including an aspect
    :name: aspect-include
    :force:

    @define PRODUCTION
    @include "aspect-macros-and-conditionals.aspect"

.. code-block:: c
    :caption: Preprocessed aspect
    :name: preprocessed-aspect-2

    # 10 "aspect-macros-and-conditionals.aspect"
    query: call(int get_property(const char *))
    {
      ;
    }

Similarly to the C programming language, you can use :ref:`comments <comments>` in aspects.
Unlike C, not all comments are eliminated at aspect preprocessing.
This is the case for comments used in :ref:`advice bodies <advice_bodies>`.
For instance, in this way you can implement so-called
`model comments <https://klever.readthedocs.io/en/latest/dev_req_specs.html#developing-model>`__ explaining particular
actions and checks performed by requirement specifications.

In addition to the possibility to describe cross-cutting concerns in the form of aspects, AOC assumes means for
automatic linkage of aspects with source files of the target program.
This process is referred to as *aspect weaving*.
In effect, for some representation of program source files, it searches for join points corresponding to advice
pointcuts specified in the aspect.
In case matches are found, join points are framed with the code specified in :ref:`advice bodies <advice_bodies>` (you
can see section :ref:`advices` for more insights).
Eventually you can get either woven in program source files or their compiled versions.

Following subsections present a formal grammar of AOC.
We use the following notation.
Nonterminals are bold and they may be links to appropriate definitions, e.g. `pointcut`, while terminals are
enclosed in double quotes, e.g. \"call\"\ [#]_.
:== following a nonterminal represents a definition of this nonterminal.
Various variants of a nonterminal definition are either placed on separate lines or separated by \|.
In nonterminal definitions optional nonterminals are enclosed in square brackets, e.g. [`pointer`].

.. note:: Keep in mind that the actual implementation may be slightly inconsistent with the given description.
          Some things may be missed while it can bring extra functionality.
          You can find known issues in the `official issue tracker <https://forge.ispras.ru/projects/cif/issues>`__.
          Please, do not hesitate to report other ones.

.. [#] Double quotes themselves are framed by single quotes like \'\"\'.

.. _tokens:

Tokens
------

Syntax
^^^^^^

.. productionlist::
   aoc-token : `c-or-aoc-keyword`
             : `aoc-identifier`
             : `aoc-integer-constant`
             : `aoc-string-literal`
             : `c-or-aoc-punctuator`
             : `file-name`
             : `advice-body`
             : `location-control-directive`
             : `comment`

Constraints
^^^^^^^^^^^

Compared to `token` defined in 6.4 of [ISO-9899-2011]_, `aoc-token` has the following amendments:

* Modified set of keywords `c-or-aoc-keyword` is used instead of `keyword` (:ref:`keywords`).
* `aoc-identifier` replaces `identifier` (:ref:`identifiers`).
* AOC supports only integer constants `aoc-integer-constant` rather than `constant` (:ref:`integer_constants`).
* `string-literal` is replaced by `aoc-string-literal` (:ref:`string_literals`).
* `aoc-punctuator` is used instead of `punctuator` (:ref:`punctuators`).

In addition, `aoc-token` supports:

* `file-name` (:ref:`file_names`).
* `advice-body` (:ref:`advice_bodies`).
* `location-control-directive` (:ref:`location_control_directives`).
* `comment` (:ref:`comments`).

We do not describe `preprocessing-token` presented in 6.4 of [ISO-9899-2011]_ according to the remark on aspect
preprocessing given in :ref:`intro`.

.. _keywords:

Keywords
--------

Syntax
^^^^^^

.. productionlist::
   c-or-aoc-keyword: `c-keyword`
                   : `aoc-keyword`
   c-keyword       : "auto"         | "char"     | "const"      | "double"
                   : "enum"         | "extern"   | "float"      | "inline"
                   : "int"          | "long"     | "register"   | "restrict"
                   : "short"        | "signed"   | "static"     | "struct"
                   : "typedef"      | "union"    | "unsigned"   | "void"
                   : "volatile"     | "_Bool"    | "_Complex"   | "_Imaginary"
   aoc-keyword     : "after"        | "around"   | "before"     | "call"
                   : "declare_func" | "define"   | "execution"  | "expand"
                   : "file"         | "get"      | "get_global" | "get_local"
                   : "infile"       | "infunc"   | "info"       | "introduce"
                   : "new"          | "pointcut" | "set"        | "set_global"
                   : "set_local"    | "query"

Constraints
^^^^^^^^^^^

In comparison with `keyword` presented in 6.4.1 of [ISO-9899-2011]_ in AOC `c-or-aoc-keyword` can be either a
`c-keyword` keyword or an AOC `aoc-keyword` keyword.
`c-keyword` does not support \"break\", \"case\", \"continue\", \"default\", \"do\", \"else\", \"for\",
\"goto\", \"if\", \"return\", \"switch\" and \"while\", i.e. those keywords that can only be used in C
statements and expressions.
You still can use them in :ref:`advice bodies <advice_bodies>`, but they are not parsed at aspect weaving.

`aoc-keyword` is the definition of AOC keywords.
It supports:

* \"after\", \"around\", \"before\", \"info\", \"new\" and \"query\" (:ref:`advices`);
* \"call\", \"define\", \"declare_func\", \"execution\", \"expand\", \"file\", \"get\", \"get_global\",
  \"get_local\", \"infile\", \"infunc\", \"introduce\", \"pointcut\", \"set\", \"set_global\" and
  \"set_local\" (:ref:`pointcuts`).

Semantics
^^^^^^^^^

Basically the semantics of keywords `c-or-aoc-keyword` corresponds to the semantics of `keyword` described in 6.4.1 of
[ISO-9899-2011]_.
An important difference is that a word can be `aoc-keyword` only outside of :ref:`comments <comments>`,
:ref:`advice bodies <advice_bodies>`, :ref:`macros <macros>` and
:ref:`declarations of functions, variables, and types <decls>`.
Besides, only words used in :ref:`declarations of functions, variables, and types <decls>` can represent keywords of the
C programming language.

.. _identifiers:

Identifiers
-----------

Syntax
^^^^^^

.. productionlist::
   aoc-identifier         : `aoc-identifier-nondigit`
                          : `aoc-identifier` `aoc-identifier-nondigit`
                          : `aoc-identifier` `digit`
   aoc-identifier-nondigit: `nondigit`
                          : "$"

Constraints
^^^^^^^^^^^

Nonterminals `digit` and `nondigit` are defined in 6.4.2 of [ISO-9899-2011]_.
Compared to `identifier`, which is presented in 6.4.2 of [ISO-9899-2011]_, AOC `aoc-identifier` supports modified set of
non-digital characters `aoc-identifier-nondigit` instead of `identifier-nondigit`.

`aoc-identifier-nondigit` does not support universal character names `universal-character-name` and any other
characters.
Additionally, `aoc-identifier-nondigit` supports wildcard \"$\" (take into account that the **$** symbol is not
included in the standard sets of non-digital characters `nondigit` and digits `digit`).
We will consider other constraints related to \"$\" in following sections.

Semantics
^^^^^^^^^

In general the semantics of `aoc-identifier` corresponds to the semantics of `identifier` described in 6.4.2 of
[ISO-9899-2011]_.
Each \"$\" wildcard in `aoc-identifier` corresponds to a sequence of characters (both `digit` and `nondigit`) of
arbitrary length\ [#]_.
For instance, `aoc-identifier` **$_property$** will match such identifiers as **get_property**, **set_property** and
**get_property_value**, but it will not match, say, **receive_message**.
If several \"$\" wildcards are contiguous in the same identifier, they are treated as one \"$\".
An identifier is not converted to a keyword if it uses at least one \"$\" wildcard.
Following sections describe specific semantics of \"$\" wildcards for certain entities.

.. [#] Everywhere in this document an arbitrary length includes zero.

.. _integer_constants:

Integer constants
-----------------

Syntax
^^^^^^

.. productionlist::
   aoc-integer-constant: `decimal-constant`

Constraints
^^^^^^^^^^^

Nonterminal `decimal-constant` is defined in 6.4.4.1 of [ISO-9899-2011]_.
Compared to `integer-constant` defined in 6.4.4.1 of [ISO-9899-2011]_, in AOC `aoc-integer-constant` does not support:

* `octal-constant`.
* `hexadecimal-constant`.
* `integer-suffix`.

Semantics
^^^^^^^^^

`aoc-integer-constant` dumbs down `integer-constant` presented in 6.4.4.1 of [ISO-9899-2011]_.
Appropriate integer constants are always stored in a variable with the *unsigned int* type (standard type conversion
rules are applied in case of overflows).

.. _string_literals:

String literals
---------------

Syntax
^^^^^^

.. productionlist::
   aoc-string-literal: '"' [`s-char-sequence`] '"'

Constraints
^^^^^^^^^^^

Nonterminal `s-char-sequence` is defined in 6.4.5 of [ISO-9899-2011]_.
Compared to `string-literal` specified in 6.4.5 of [ISO-9899-2011]_, `aoc-string-literal` does not support wide string
literals L\" s-char-sequenceopt \".

Semantics
^^^^^^^^^

`aoc-string-literal` is a simplification of `string-literal` presented in 6.4.5 of [ISO-9899-2011]_.

.. _punctuators:

Punctuators
-----------

Syntax
^^^^^^

.. productionlist::
   c-or-aoc-punctuator: `c-punctuator`
                      : `aoc-punctuator`
   c-punctuator       : "(" | ")" | "[" | "]" | "*" | "..." | "," | "$" | ".."
   aoc-punctuator     : "(" | ")" | ":" | "!" | "&&" | "||"

Constraints
^^^^^^^^^^^

In comparison with `punctuator`, which is presented in 6.4.6 of [ISO-9899-2011]_, in AOC `c-or-aoc-punctuator` can be
either punctuator of the C programming language `c-punctuator`, or AOC punctuator `aoc-punctuator`.
The definition of `c-punctuator` supports only \"(\", \")\", \"[\", \"]\", \"\*\", \"\...\" and \",\" from the
`punctuator` definition, i.e. those punctuators that can be used when writing :ref:`macros <macros>` and
:ref:`declarations of functions, variables, and types <decls>`.
Besides, `c-punctuator` supports following extra punctuators:

* \"$\" -- a universal type specifier or a universal array size (:ref:`decls`).
* \"..\" -- a list of arbitrary parameters of a macro function or a function of arbitrary length (see :ref:`macros` and
  :ref:`decls` for more details).

The `aoc-punctuator` definition includes:

* \":\" -- it introduces a definition of a :ref:`named pointcut <pointcuts>` or :ref:`advice <advices>`.
* \"(\", \")\", \"!\", \"&&\", \"||\" -- these punctuators are for the sake of development of
  :ref:`composite pointcuts <pointcuts>`.
* \"(\", \")\" -- braces also separate :ref:`macros <macros>` and
  :ref:`declarations of functions, variables, and types <decls>` from descriptions of :ref:`pointcuts <pointcuts>` and
  :ref:`advices <advices>`.

Semantics
^^^^^^^^^

The semantics of `c-or-aoc-punctuator` generally corresponds to the semantics of `punctuator` described in 6.4.6 of
[ISO-9899-2011]_.
A vital difference is that a punctuator can be `aoc-punctuator` only outside of :ref:`comments <comments>`,
:ref:`advice bodies <advice_bodies>`, :ref:`macros <macros>` and
:ref:`declarations of functions, variables, and types <decls>`.
Besides, only punctuators used in macros and declarations of functions, variables and composite types are considered as
punctuators of the C programming language (:ref:`macros` and :ref:`decls`).
The semantics of additional punctuators of `c-punctuator` is discussed in detail in sections :ref:`macros` and
:ref:`decls`.
Sections :ref:`pointcuts` and :ref:`advices` delves into the semantics of `aoc-punctuator`.
We do not consider punctuators used in :ref:`special directives <special_directives>` here, because they have no meaning
outside the context of special directives that are parsed in a special way.

.. _file_names:

File names
----------

Syntax
^^^^^^

.. productionlist::
   file-name: '"' `q-char-sequence` '"'

Constraints
^^^^^^^^^^^

The `q-char-sequence` nonterminal is defined in 6.4.7 of [ISO-9899-2011]_.

Semantics
^^^^^^^^^

Basically the semantics of `file-name` corresponds to the semantics of `header-name` described in 6.4.7 of
[ISO-9899-2011]_.
Some specific character sequences in file names are interpreted as follows:

* One or more **$$**\ [#]_.
  Each **$$** corresponds to sequence of q-characters `q-char-sequence` of arbitrary length.
  If several **$$** are contiguous in the same file name, they are treated as one **$$**.
* Special directive **$this** that can be used only to indicate the file name and only in the form of \"**$this**\"
  (:ref:`special_directives`).
* Special directives with predefined values (see :ref:`special_directives` for more details).

.. note:: Generally speaking, one can use **$** characters in file names but this is not considered in AOC.

.. [#] A pair of **$** characters is used to avoid collisions with :ref:`special directives <special_directives>`.

.. _advice_bodies:

Advice bodies
-------------

Syntax
^^^^^^

.. productionlist::
   advice-body: "{" compound-statement-with-comments-and-special-directives "}"

Constraints
^^^^^^^^^^^

`advice-body` represents a C code enclosed in curly braces.
It is similar to `compound-statement` of `function-definition` from 6.9.1 of [ISO-9899-2011]_.
In advice bodies one can use any correct C code with `GCC <https://gcc.gnu.org/>`__ compiler extensions that can be used
in function bodies.
In addition, advice bodies may contain :ref:`comments <comments>` and :ref:`special directives <special_directives>`
which reflect information about joint points or have some special purpose.
For example, special directive **$arg_numb** denotes the number of function parameters, **$fprintf** is intended for
formatted output of data to a file, **$env** denotes a value of an environment variable.

Semantics
^^^^^^^^^

Advice bodies are not parsed except for :ref:`special directives <special_directives>` and :ref:`comments <comments>`.
Special directives are substituted with corresponding values either during parsing of aspects (so-called special
directives with predefined values) or at aspect weaving.
Comments are ignored to correctly balance curly braces and determine ends of advice bodies.
After parsing comments remain in advice bodies as is.
This is necessary in order to keep, say, model comments.

.. _special_directives:

Special directives
------------------

Syntax
^^^^^^

.. productionlist::
   special-directive               : "$" `aoc-identifier` [`aoc-integer-constant`]
                                   : "$" `aoc-identifier` [`aoc-integer-constant`] "<" `special-directive-parameter-list` ">"
   special-directive-parameter-list: `special-directive-parameter`
                                   : `special-directive-parameter-list` "," `special-directive-parameter`
   special-directive-parameter     : `special-directive`
                                   : `aoc-integer-constant`
                                   : `aoc-string-literal`

Constraints
^^^^^^^^^^^

`special-directive` can be used only in `advice-body` and `file-name`.
In order to avoid collisions with the C code used in advice bodies along with special directives, it is prohibited
to use whitespace characters in special directives except for separating special directive parameters from each other.
All special directives start with the **$** symbol which cannot be used in the C code.

`identifier` defines a type of special directive.
The following types of special directives are supported: **$arg**, **$arg_numb**, **$arg_sign**, **$arg_size**,
**$arg_type**, **$arg_val**, **$context_file**, **$context_func_file**, **$context_func_name**, **$env**, **$fprintf**,
**$name**, **$proceed**, **$res**, **$ret_type**, **$storage_class**, **$signature** and **$this**.
It is forbidden to use digits in `identifier` of `special-directive`.
This is done to avoid collisions of identifiers with `aoc-integer-constant` that may be a part of special directives.

`aoc-integer-constant` of `special-directive` should be used only together with **$arg**, **$arg_sign**, **$arg_size**,
**$arg_type** or **$arg_val**.
These integer constants can only refer ordinal numbers of arguments of functions or macros from appropriate join points.
Numbering begins with 1.
You can not separate `aoc-integer-constant` from `aoc-identifier` as it was stated above.

`special-directive-parameter-list` should be used only along with **$env** and **$fprintf**.
The only parameter allowed for **$env** is `aoc-string-literal`.
This string literal should exactly match a name of one of environment variables.
You can use any number of parameters for **$fprintf** but at least two parameters are mandatory.
The first parameter should be either a string literal or a special directive with a predefined value which is also a
string literal.
This string literal should represent a file name (either relative or absolute path) that can be opened for writing\ [#]_.
The second parameter should be `aoc-string-literal`.
This string literal represents simplified **format** defined in 7.21.6.1 of [ISO-9899-2011]_.
Only **%d** and **%s** specifiers are acceptable.
They should match `aoc-integer-constant` and `aoc-string-literal` respectively among other parameters of special
directives.
Also, any of these parameters can be a special directive whose value is `aoc-integer-constant` or `aoc-string-literal`.
:numref:`preprocessed-aspect` contains an example of **$fprintf**.

Semantics
^^^^^^^^^

All special directives except **$fprintf** are replaced with some values: `integers <aoc-integer-constant>`,
`identifiers <aoc-identifier>` without **$** wildcards or `string literals <aoc-string-literal>`.

Special directive **$fprintf** performs formatted data output to a specified file in the same way as standard C function
*fprintf* described in 7.21.6.1 of [ISO-9899-2011]_.

Special directives **$env** and **$this** are the only special directives with predefined values.
These values are determined at the stage of aspect parsing.
Instead of **$env** a value of a corresponding environment variable is substituted.
**$this** is identified with a name of a woven in C source file.

The remaining special directives are substituted at aspect weaving as follows:

* **$arg**\ *i* -- a name of i\ :sup:`th` formal parameter of a function or macro.
* **$arg_numb** -- the number of parameters of a function or macro.
* **$arg_sign**\ *i* -- a signature of i\ :sup:`th` actual parameter of a function.
  An *argument signature* is an identifier based on a syntax tree of a corresponding argument.
  Argument signatures should be built in a way to distinguish arguments corresponding to different memory objects
  unambiguously though it is not always possible.
* **$arg_size**\ *i* -- an array size if i\ :sup:`th` actual parameter of a function is a pointer to a one-dimensional
  array or **-1** otherwise.
* **$arg_type**\ *i* -- a type of i\ :sup:`th` formal parameter of a function.
  A corresponding type is provided by using *typedef*, so function pointers are also supported.
* **$arg_val**\ *i* -- a function name if i\ :sup:`th` actual parameter of a function is an address of some known function
  or **0** otherwise.
* **$context_file** -- a path to a file containing a join point.
* **$context_func_file** -- a path to a file that defines a function containing a join point.
* **$context_func_name** -- a name of a function containing a join point.
* **$name** -- a name of a macro, function, variable or composite type corresponding to a join point.
* **$proceed** -- a join point itself, for example, an original function call.
* **$res** -- a function return value (it is provided by a special variable).
* **$ret_type** -- a type of function's return value or variable or a composite type (it is provided via *typedef*).
* **$storage_class** -- a storage class of a function or global variable.

.. [#] This file is created if it does not exist.

.. _location_control_directives:

Location control directives
---------------------------

Syntax
^^^^^^

.. productionlist::
   location-control-directive: "#" `aoc-integer-constant` `aoc-string-literal` `new-line`

Constraints
^^^^^^^^^^^

The `new-line` nonterminal is defined in 5.2.1 of [ISO-9899-2011]_.

Location control directives (aka *line directives*) can be used outside of :ref:`advice bodies <advice_bodies>`.
They should occupy exactly one line.

Semantics
^^^^^^^^^

The semantics of `location-control-directive` generally corresponds to the semantics of line control preprocessing
directives described in 6.10.4 of [ISO-9899-2011]_.
In the `location-control-directive` definition `aoc-integer-constant` points out line numbers in files whose names are
specified by `aoc-string-literal`.

`line directives <location-control-directive>` can arise at aspect preprocessing considered in :ref:`intro`.
Users should unlikely use them.

.. _comments:

Comments
--------

Outside of `comment` the **//** symbols indicate the beginning of a one-line comment.
The content of this comment is scanned only to detect the `new-line` character that ends it up and that is not included
in the comment itself.
Outside of `comment` the **/*** characters indicate the beginning of a multiline comment.
The content of this comment is scanned only to detect the ***/** characters that end it.

On aspect preprocessing all comments always remain in the text of the resulting file with the aspect.
This is done in order to keep, say, model comments.
For a similar reason comments are kept within advice bodies at aspect parsing and aspect weaving.

.. _macros:

Macros
------

Syntax
^^^^^^

.. productionlist::
   macro                       : `identifier`
                               : `identifier` "(" [`identifier-or-any-param-list`] ")"
                               : `identifier` "(" [`identifier`] "..." ")"
                               : `identifier` "(" `identifier-or-any-param-list` "," [`identifier`] "..." ")"
   identifier-or-any-param-list: `identifier`
                               : ".."
                               : `identifier-or-any-param-list` "," `identifier`

Constraints
^^^^^^^^^^^

In comparison with preprocessor directives defined in 6.10 of [ISO-9899-2011]_, in AOC `macro` supports a
`GCC <https://gcc.gnu.org/>`__ compiler extension that allows associating a name to \"\...\" in the form of optional
`identifier` before it.
\"\...\" designates a list of arbitrary macro parameters of arbitrary length.
Also, `identifier-or-any-param-list` supports the \"..\" wildcard.
It means a list of arbitrary macro parameters of arbitrary length.

Semantics
^^^^^^^^^

In general, the semantics of `macro` corresponds to the semantics of preprocessor directives described in 6.10 of
[ISO-9899-2011]_.
Wildcard \"..\" matches a list of arbitrary macro parameters of arbitrary length at a joint point.
For instance, **LOCK(x, ..)** will match both **LOCK(x)**, **LOCK(x, y)** and **LOCK(x, y, z)**, but it will not match
**LOCK()** and **LOCK**.
If there are several consecutive \"..\" separated by commas, they are treated as one \"..\".

.. _decls:

Declarations of functions, variables, and types
-----------------------------------------------

Syntax
^^^^^^

.. productionlist::
   declaration               : `declaration-specifiers` [`declarator`]
   declaration-specifiers    : `storage-class-specifier` [`declaration-specifiers`]
                             : `type-specifier` [`declaration-specifiers`]
                             : `type-qualifier` [`declaration-specifiers`]
                             : ".." [`declaration-specifiers`]
                             : "..."
   storage-class-specifier   : "typedef"
                             : "extern"
                             : "static"
                             : "auto"
                             : "register"
   type-specifier            : "void"
                             : "char"
                             : "short"
                             : "int"
                             : "long"
                             : "float"
                             : "double"
                             : "signed"
                             : "unsigned"
                             : "_Bool"
                             : "_Complex"
                             : `struct-or-union-specifier`
                             : `enum-specifier`
                             : `typedef-name`
                             : "$"
   struct-or-union-specifier : `struct-or-union` `identifier`
   struct-or-union           : "struct"
                             : "union"
   enum-specifier            : "enum" `identifier`
   typedef-name              : `identifier`
   type-qualifier            : "const"
                             : "restrict"
                             : "volatile"
   function-specifier        : "inline"
   declarator                : [`pointer`] `direct-declarator`
   direct-declarator         : `identifier`
                             : "(" `declarator` ")"
                             : `direct-declarator` "[" [`integer-constant`] "]"
                             : `direct-declarator` "[" "$" "]"
                             : `direct-declarator` "(" `parameter-type-list` ")"
   pointer                   : "*" [`type_qualifier_list`]
                             : "*" [`type_qualifier_list`] `pointer`
   type_qualifier_list       : `type-qualifier`
                             : `type_qualifier_list` `type-qualifier`
   parameter-type-list       : `parameter-list`
   parameter-list            : `parameter-declaration`
                             : `parameter-list` "," `parameter-declaration`
   parameter-declaration     : `declaration-specifiers` `declarator`
                             : `declaration-specifiers` `abstract-declaratoropt`
   abstract-declarator       : `pointer`
                             : [`pointer`] `direct-abstract-declarator`
   direct-abstract-declarator: "(" `abstract-declarator` ")"
                             : "[" `direct-abstract-declarator` "]" "[" [`integer-constant`] "]"
                             : [`direct-abstract-declarator`] "[" "$" "]"
                             : [`direct-abstract-declarator`] "(" [`parameter-type-list`] ")"

Constraints
^^^^^^^^^^^

In comparison with `declaration` that represents declarations of functions, variables, and types and that is defined in
6.7 of [ISO-9899-2011]_, AOC `declaration` have the following differences:

* It does not support `init-declarator-list`.
  Only `declarator` itself can be used instead.
* `struct-or-union-specifier` does not support specifying structure or union fields.
* `enum-specifier` does not support setting enumeration constants.
* The `direct-declarator` definition does not support:

  * Various forms of array assignment.
  * The outdated form of providing function parameters.

* `parameter-type-list` does not support \"\...\" that designates a list of arbitrary function parameters of
  arbitrary length (it is supported at the level of `declaration-specifiers` which is discussed below).
* The `direct-abstract-declarator` definition does not support various forms of array assignment.
* `declaration-specifiers` additionally supports:

  * Wildcard \"..\" capturing a list of arbitrary function parameters of arbitrary length.
  * \"\...\" that designates a list of arbitrary function parameters of arbitrary length.
    This works only for declarations from `parameter-list`.

* The `type-specifier` definition supports universal type specifier \"$\" in addition.
  One declaration can contain no more than one universal type specifier among all its specifiers.
  This restriction is important since exactly the same wildcard can be used in place of a declaration name.
  For a structure, union, or enumeration declaration a corresponding type specifier should be specified.
  This is necessary to distinguish declarations using two \"$\" symbols that match variables or functions.
  For example, **$ $** can correspond to variables such as *int var1*, *static long int var2* and *char var3[10]*, but
  it does not match *struct S*, *union U* and *enum E* types.
  For the latter you can use **struct $**, **union $** and **enum $** respectively.
* `direct-declarator` and `direct-abstract-declarator` supports universal array size \"$\".

Semantics
^^^^^^^^^

Declarations are distinguished in the following way.
Absence of `declarator` in the `declaration` definition means that this declaration is a composite type declaration.
If `declarator` is present then the declaration is either a function declaration (if there is `parameter-type-list`) or
a variable.

Wildcard \"..\" in the definition of `declaration-specifiers` corresponds to a list of arbitrary function parameters
of arbitrary length at a joint point.
Several consecutive, separated by commas \"..\" are treated as one \"..\".

As a matter of fact \"\...\" in `declaration-specifiers` exactly coincides with the same terminal in
`parameter-type-list` (6.7.6 of [ISO-9899-2011]_).
The need to transfer it arose due to the ambiguity of the grammar otherwise.

Basically the semantics of `declaration` corresponds to the semantics of `declaration` described in 6.7 of
[ISO-9899-2011]_.

Universal type specifier \"$\" in the definition of `type-specifier` means the following:

* If the universal type specifier is located before any other type specifier, then it denotes a list of arbitrary
  declaration specifiers of arbitrary length (the \"$\" symbol does not match arbitrary `typedef-name`).
  For instance, **$** matches **char**, **int**, **unsigned int**, **static inline int** and so on.
* If the universal type specifier is the only type specifier among declaration specifiers (according to the restriction
  specified earlier, it can be functions or variables only), then it denotes a type of variable or return value of a
  function, which is arbitrary up to the specified declaration specifiers.
  For instance, **$ int** matches **int**, **unsigned int** and **static inline int**, but it does not match, say,
  **char**.

Universal array size \"$\" in definitions of `direct-declarator` and `direct-abstract-declarator` corresponds to an
arbitrary array size at a joint point.
For example, **int array[$]** will match both **int array[3]** and **int array[5]**.

.. _pointcuts:

Pointcuts
---------

Syntax
^^^^^^

.. productionlist::
   named-pointcut    : "pointcut" `identifier` ":" `pointcut`
   pointcut          : `identifier`
                     : `primitive-pointcut`
                     : `composite-pointcut`
   composite-pointcut: "!" `pointcut`
                     : `pointcut`1 "||" `pointcut`2
                     : `pointcut`1 "&&" `pointcut`2
                     : "(" `pointcut` ")"
   primitive-pointcut: "define" "(" `macro` ")"
                     : "expand" "(" `macro` ")"
                     : "declare_func" "(" `declaration` ")"
                     : "execution" "(" `declaration` ")"
                     : "call" "(" `declaration` ")"
                     : "get" "(" `declaration` ")"
                     : "get_global" "(" `declaration` ")"
                     : "get_local" "(" `declaration` ")"
                     : "infunc" "(" `declaration` ")"
                     : "introduce" "(" `declaration` ")"
                     : "set" "(" `declaration` ")"
                     : "set_global" "(" `declaration` ")"
                     : "set_local" "(" `declaration` ")"
                     : "file" "(" `file-name` ")"
                     : "infile" "(" `file-name` ")"

Constraints
^^^^^^^^^^^

It is forbidden to use \"$\" wildcards in `identifier` in the definition of `named-pointcut`.
Preprocessed aspect files can not define several `named pointcuts <named-pointcut>` with the same `identifier`.

`identifier` can be only an identifier of a previously defined named pointcut in the definition of `pointcut`.
It also can not use \"$\" wildcards.

Strictly speaking `pointcut1 <pointcut>` and `pointcut2 <pointcut>` represent different pointcuts in the definition of
`composite-pointcut`.

The definition of `primitive-pointcut` has following constraints (you can find extra details about declarations in
:ref:`decls`):

* `declaration` for \"declare_func\", \"execution\" and \"call\" should be only a function declaration.
* `declaration` for \"get\", \"get_global\", \"get_local\", \"set\", \"set_global\" and \"set_local\" should
  be only a variable declaration.
* `declaration` for \"introduce\" should be only a declaration of a composite type.

Semantics
^^^^^^^^^

`named-pointcut` binds `pointcut` to `identifier` that one can use in other pointcuts to refer the given one.

`composite-pointcut` is a composition of pointcuts obtained using parentheses and operators \"!\", \"&&\" and
\"||\".
The precedence of operators \"!\", \"&&\" and \"||\" decreases left to right.

`primitive-pointcut` describes the following sets of joint points:

* \"define\" and \"expand\" -- respectively a definition or substitution of `macro`.
* \"declare_func\", \"execution\" and \"call\" -- correspondingly a declaration, definition, or call of a function
  having appropriate `declaration`.
* \"get\" and \"set\" -- respectively a usage or assignment of a value to a variable with corresponding
  `declaration`.
* \"get_global\", \"set_global\", \"get_local\" and \"set_local\" -- the same as the previous primitive
  pointcut, but global and local (including function parameters) variables are distinguished.
* \"infunc\" -- join points in a context of a function with specified `declaration`.
* \"introduce\" -- a definition of a structure, union, or enumeration with specified `declaration`.
* \"file\" -- a file with `file-name`.
* \"infile\" -- join points in a context of a file with `file-name`.

.. _advices:

Advices
-------

Syntax
^^^^^^

.. productionlist::
   advice            : `advice-declaration` `advice-body`
   advice-declaration: "before" ":" `pointcut`
                     : "around" ":" `pointcut`
                     : "after"  ":" `pointcut`
                     : "info"   ":" `pointcut`
                     : "new"    ":" `pointcut`
                     : "query"  ":" `pointcut`

.. note:: \"info\" is a deprecated alias for \"query\".
          You can use any of them, but \"query\" is more preferable.

.. note:: It is not recommended to use \"new\".

Constraints
^^^^^^^^^^^

Each advice should consist of `advice-declaration` and `advice-body`.
Any `pointcut` is allowed for `advice-declaration` with \"before\", \"around\", \"after\" and \"query\".
Only `primitive-pointcut` corresponding to `file-name` is allowed for \"new\" `advice-declaration`.

.. TODO: $signature looks strange in the first list. Unlikely it works for "new".

In `advice-body` of \"before\", \"around\", \"after\", \"new\" and \"query\" one can use special directives
\"$env\", \"$fprintf\" (if other special directives represent its parameters, then similar restrictions are imposed
on them) and \"$signature\".
Besides, in `advice-body` of \"before\", \"around\", \"after\" and \"query\" it is possible to use the following
special directives when `pointcut` matches an appropriate joint point:

* For macro definitions -- \"$arg\", \"$arg_numb\", \"$context_file\", \"$name\" and \"$proceed\".
* For macro substitutions -- \"$arg\", \"$arg_numb\", \"$arg_val\" (a value of an actual macro parameter as is),
  \"$context_file\", \"$name\" and \"$proceed\".
* For function calls -- \"$arg\", \"$arg_numb\", \"$arg_sign\", \"$arg_size\", \"$arg_type\", \"$arg_val\",
  \"$context_file\", \"$context_func_file\", \"$context_func_name\", \"$name\", \"$proceed\", \"$res\"
  (only for \"after\"), \"$ret_type\" and \"$storage_class\".
* For function declarations -- \"$arg_numb\", \"$arg_type\", \"$context_file\", \"$name\", \"$ret_type\" and
  \"$storage_class\".
* For function definitions -- \"$arg\", \"$arg_numb\", \"$arg_type\", \"$context_file\", \"$name\",
  \"$proceed\", \"$res\" (only for \"after\"), \"$ret_type\" and \"$storage_class\".
* For usages and assignments of values to local or global variables -- \"$context_file\", \"$context_func_file\",
  \"$context_func_name\", \"$name\", \"$proceed\", \"$res\" (only for \"after\"), \"$ret_type\" (a matched variable
  type) and \"$storage_class\" (only for global variables).
* For declarations of composite types -- \"$context_file\", \"$name\" and \"$ret_type\" (a matched composite
  type).

Semantics
^^^^^^^^^

`pointcut` included in `advice-declaration` determines a set of join points for which this advice should be applied,
that assumes either executing the code from `advice-body` or framing join points with it.

\"before\", \"after\" and \"around\" advices are applied before, after or instead matched join points
respectively.
\"around\" advices can also wrap corresponding join points indicated by the \"$proceed\" special directive in
`advice-body`.

\"query\" advices do not change the program code.
These advices are used only for formatted output of information about joint points to a file by means of special
directives \"$fprintf\".

The \"new\" advice creates a file that is specified in \"pointcut\".
This feature allows, for example, to declare common variables and functions for several C source files.

In `advice-body` it is allowed to write arbitrary correct C code with `GCC <https://gcc.gnu.org/>`__ compiler extensions
as well as a set of special directives (:ref:`special_directives`).
You can use only special directives \"$fprintf\" in bodies of \"query\" advices (parameters of this special
directive may be other valid special directives).

If parameter names are used in `parameter-type-list`, then you can use them to refer corresponding parameters in
`advice-body`.

.. TODO: This does not WAI. Maybe this is not so bad.

    If several advices match the same join point, they are applied in the following order:

    #. Among advices of the same type (\"before\", \"around\", \"after\", \"new\" and \"query\"), the one that
       occurs earlier in the aspect file is applied first.
    #. First of all, \"before\" advices are applied to the join point.
    #. Then \"around\" advices are applied as follows:

       #. If there is no special directive \"$proceed\" in `advice-body` of the currently applied advice, then its
          application is terminated.
       #. Otherwise, the part of this advice is applied before special directive\"$proceed\".
          Then instead of this special directive, the following \"around\" advice if any is applied or the join point
          itself is executed directly.

    #. After all \"after\" advices are applied.

If several advices match the same join point, then only the one that occurs earlier in the aspect file is applied.
For more complex cases, for example, when a program is woven in with several aspects at once, the behavior of the aspect
weaver is uncertain.

.. _aspects:

Aspects
-------

Syntax
^^^^^^

.. productionlist::
   text                         : [`advice-or-named-pointcut-list`]
   advice-or-named-pointcut-list: `advice-or-named-pointcut-list` `advice`
                                : `advice-or-named-pointcut-list` `named-pointcut`

Constraints
^^^^^^^^^^^

Aspects should be placed in separate files.
After performing aspect preprocessing (see :ref:`intro` for details), each aspect can either be empty or consist of one
or more :ref:`advices <advices>` and :ref:`named pointcuts <pointcuts>`.
In addition, :ref:`line directives <location_control_directives>` and :ref:`comments <comments>` can be used.

Semantics
^^^^^^^^^

Aspects are additional modules that describe the cross-cutting concerns of programs.

.. [ISO-9899-2011] ISO/IEC 9899:2011 Information technology -- Programming languages -- C
