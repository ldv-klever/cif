void func1(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
void func1(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
static void cif_func1(void);
#line 1 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
void func2(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
void func2(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
static void cif_func2(void);
#line 2 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
void func3(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
void func3(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
static void cif_func3(void);
#line 3 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
int func5(void);
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
int func5(void);
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
static int cif_func5(void);
#line 4 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
int func6(void);
#line 6 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
int func6(void);
#line 6 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
static int cif_func6(void);
#line 6 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
void func7(int arg)
{
  switch (cif_func5 ( ) + arg)
  {
#line 9 "/home/novikov/work/cif-gcc-11/tests/input/stmts/switch.c"
    case 3:;
    cif_func3 ( );
    break;
    case 5:;
    cif_func1 ( );
    case 6:;
    cif_func6 ( );
    break;
    default:;
    cif_func2 ( );
  }
}
#line 3 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
static int cif_func5(void)
{
  typedef int ldv_func_ret_type;
#line 7 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  ldv_func_ret_type ldv_func_res = func5 ( );
#line 9 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  return 0;
#line 11 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  return ldv_func_res;
}
#line 15 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
static void cif_func3(void)
{
#line 18 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  return;
}
#line 22 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
static void cif_func1(void)
{
#line 25 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  return;
#line 27 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  func1 ( );
}
#line 31 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
static int cif_func6(void)
{
#line 34 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  return 0;
}
#line 38 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
static void cif_func2(void)
{
#line 41 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  func2 ( );
#line 43 "/home/novikov/work/cif-gcc-11/tests/work/switch.c.aux"
  return;
}
