void func1(void);
void func1(void);
#line 2 "/home/novikov/work/cif/tests/input/func-calls.c"
static void cif_func1(void);
#line 2 "/home/novikov/work/cif/tests/input/func-calls.c"
void func2(void);
void func2(void);
#line 3 "/home/novikov/work/cif/tests/input/func-calls.c"
static void cif_func2(void);
#line 3 "/home/novikov/work/cif/tests/input/func-calls.c"
void func3(void);
void func3(void);
#line 4 "/home/novikov/work/cif/tests/input/func-calls.c"
static void cif_func3(void);
#line 4 "/home/novikov/work/cif/tests/input/func-calls.c"
int func4(void);
int func4(void);
#line 5 "/home/novikov/work/cif/tests/input/func-calls.c"
static int cif_func4(void);
#line 5 "/home/novikov/work/cif/tests/input/func-calls.c"
int func5(void);
int func5(void);
#line 6 "/home/novikov/work/cif/tests/input/func-calls.c"
static int cif_func5(void);
#line 6 "/home/novikov/work/cif/tests/input/func-calls.c"
int func6(void);
int func6(void);
#line 7 "/home/novikov/work/cif/tests/input/func-calls.c"
static int cif_func6(void);
void func7(void)
{
  cif_func1 ( );
  cif_func2 ( );
  cif_func3 ( );
  cif_func4 ( );
  cif_func5 ( );
  cif_func6 ( );
}
#line 3 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
static void cif_func1(void)
{
#line 6 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return;
#line 8 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  func1 ( );
}
#line 12 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
static void cif_func2(void)
{
#line 15 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  func2 ( );
#line 17 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return;
}
#line 21 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
static void cif_func3(void)
{
#line 24 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return;
}
#line 28 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
static int cif_func4(void)
{
#line 31 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return 0;
#line 33 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return func4 ( );
}
#line 37 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
static int cif_func5(void)
{
  typedef int ldv_func_ret_type;
#line 41 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  ldv_func_ret_type ldv_func_res = func5 ( );
#line 43 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return 0;
#line 45 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return ldv_func_res;
}
#line 49 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
static int cif_func6(void)
{
#line 52 "/home/novikov/work/cif/tests/work/func-calls.c.aux"
  return 0;
}
