You can find the CIF documentation online at http://cif.readthedocs.io or build it yourself.

To build the CIF documentation you need:
* Install [Python 3.4 or higher](https://www.python.org/).
* Install [Sphinx](http://sphinx-doc.org) and its
  [Read the Docs theme](https://sphinx-rtd-theme.readthedocs.io/en/latest/), e.g.:

      pip3 install sphinx sphinx_rtd_theme

  or in a more reliable way:

      pip3 install -r docs/requirements.txt

* Execute the following command from the source tree root directory (it should be executed each time when the
  documentation might be changed):

      make -C docs html

Then you can open generated documentation index "docs/_build/html/index.html" in a web browser.
