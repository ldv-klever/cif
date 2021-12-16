int func5(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/do-while.c"
int func5(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/do-while.c"
static int cif_func5(void);
#line 1 "/home/novikov/work/cif-gcc-11/tests/input/stmts/do-while.c"
int func6(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/do-while.c"
int func6(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/do-while.c"
static int cif_func6(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/do-while.c"
void func7(int arg)
{
  do
     cif_func6 ( ); while (arg
#line 7 "/home/novikov/work/cif-gcc-11/tests/input/stmts/do-while.c"
  ++!= cif_func5 ( ) + 10);
}
#line 3 "/home/novikov/work/cif-gcc-11/tests/work/do-while.c.aux"
static int cif_func5(void)
{
  typedef int ldv_func_ret_type;
#line 7 "/home/novikov/work/cif-gcc-11/tests/work/do-while.c.aux"
  ldv_func_ret_type ldv_func_res = func5 ( );
#line 9 "/home/novikov/work/cif-gcc-11/tests/work/do-while.c.aux"
  return 0;
#line 11 "/home/novikov/work/cif-gcc-11/tests/work/do-while.c.aux"
  return ldv_func_res;
}
#line 15 "/home/novikov/work/cif-gcc-11/tests/work/do-while.c.aux"
static int cif_func6(void)
{
#line 18 "/home/novikov/work/cif-gcc-11/tests/work/do-while.c.aux"
  return 0;
}
