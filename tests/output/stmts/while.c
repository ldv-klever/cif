void func2(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/while.c"
void func2(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/while.c"
static void cif_func2(void);
#line 1 "/home/novikov/work/cif-gcc-11/tests/input/stmts/while.c"
int func5(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/while.c"
int func5(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/while.c"
static int cif_func5(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/while.c"
void func7(int arg)
{
  while (cif_func5 ( ) + arg--!= 0)
    cif_func2 ( );
}
#line 3 "/home/novikov/work/cif-gcc-11/tests/work/while.c.aux"
static int cif_func5(void)
{
  typedef int ldv_func_ret_type;
#line 7 "/home/novikov/work/cif-gcc-11/tests/work/while.c.aux"
  ldv_func_ret_type ldv_func_res = func5 ( );
#line 9 "/home/novikov/work/cif-gcc-11/tests/work/while.c.aux"
  return 0;
#line 11 "/home/novikov/work/cif-gcc-11/tests/work/while.c.aux"
  return ldv_func_res;
}
#line 15 "/home/novikov/work/cif-gcc-11/tests/work/while.c.aux"
static void cif_func2(void)
{
#line 18 "/home/novikov/work/cif-gcc-11/tests/work/while.c.aux"
  func2 ( );
#line 20 "/home/novikov/work/cif-gcc-11/tests/work/while.c.aux"
  return;
}
