void func1(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
void func1(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
static void cif_func1(void);
#line 1 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
void func2(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
void func2(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
static void cif_func2(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
void func3(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
void func3(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
static void cif_func3(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
int func5(void);
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
int func5(void);
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
static int cif_func5(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
int func6(void);
#line 6 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
int func6(void);
#line 6 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
static int cif_func6(void);
#line 6 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
void func7(int arg)
{
  if (cif_func5 ( ) != arg)
  {
#line 9 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
    cif_func1 ( );
  }
  else
#line 10 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
    if (cif_func6 ( ) != - arg)
    {
#line 11 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
      cif_func2 ( );
    }
    else
#line 13 "/home/novikov/work/cif-gcc-11/tests/input/stmts/if-else.c"
      cif_func3 ( );
}
#line 3 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
static int cif_func5(void)
{
  typedef int ldv_func_ret_type;
#line 7 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  ldv_func_ret_type ldv_func_res = func5 ( );
#line 9 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  return 0;
#line 11 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  return ( int ) ldv_func_res;
}
#line 15 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
static void cif_func1(void)
{
#line 18 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  return;
#line 20 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  func1 ( );
}
#line 24 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
static int cif_func6(void)
{
#line 27 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  return 0;
}
#line 31 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
static void cif_func2(void)
{
#line 34 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  func2 ( );
#line 36 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  return;
}
#line 40 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
static void cif_func3(void)
{
#line 43 "/home/novikov/work/cif-gcc-11/tests/work/if-else.c.aux"
  return;
}
