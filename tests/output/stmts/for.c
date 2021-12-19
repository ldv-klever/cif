void func1(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
void func1(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
static void cif_func1(void);
#line 1 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
int func4(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
int func4(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
static int cif_func4(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
int func5(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
int func5(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
static int cif_func5(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
int func6(void);
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
int func6(void);
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
static int cif_func6(void);
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
void func7(int arg)
{
  {
#line 7 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
    int i = cif_func4 ( );
#line 7 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
    for ( ; cif_func5 ( ) > i ; i = ( func6 ( ) ) + i )
    {
      {
#line 8 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
        int j = cif_func6 ( );
#line 8 "/home/novikov/work/cif-gcc-11/tests/input/stmts/for.c"
        for ( ; cif_func5 ( ) < j ; j -= ( func4 ( ) ) )
           cif_func1 ( );
      }
      if (i == arg)
        continue;
      if (- arg == i)
        break;
    }
  }
}
#line 3 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
static int cif_func4(void)
{
#line 6 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  return 0;
#line 8 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  return func4 ( );
}
#line 12 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
static int cif_func5(void)
{
  typedef int ldv_func_ret_type;
#line 16 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  ldv_func_ret_type ldv_func_res = func5 ( );
#line 18 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  return 0;
#line 20 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  return ( int ) ldv_func_res;
}
#line 24 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
static int cif_func6(void)
{
#line 27 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  return 0;
}
#line 31 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
static void cif_func1(void)
{
#line 34 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  return;
#line 36 "/home/novikov/work/cif-gcc-11/tests/work/for.c.aux"
  func1 ( );
}
