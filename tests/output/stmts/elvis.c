int func4(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
int func4(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
static int cif_func4(void);
#line 1 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
int func5(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
int func5(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
static int cif_func5(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
int func6(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
int func6(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
static int cif_func6(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/elvis.c"
void func7(int arg)
{
  cif_func6 ( ) != arg ? cif_func4 ( ) : cif_func5 ( );
}
#line 3 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
static int cif_func6(void)
{
#line 6 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
  return 0;
}
#line 10 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
static int cif_func4(void)
{
#line 13 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
  return 0;
#line 15 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
  return func4 ( );
}
#line 19 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
static int cif_func5(void)
{
  typedef int ldv_func_ret_type;
#line 23 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
  ldv_func_ret_type ldv_func_res = func5 ( );
#line 25 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
  return 0;
#line 27 "/home/novikov/work/cif-gcc-11/tests/work/elvis.c.aux"
  return ldv_func_res;
}
