void func1(void);
void func1(void);
#line 2 "/home/novikov/work/cif/tests/input/func-calls.c"
static void cif_func1(void);
#line 2 "/home/novikov/work/cif/tests/input/func-calls.c"
void func2(void);
void func3(void);
int func4(void);
int func5(void);
int func6(void);
#line 8 "/home/novikov/work/cif/tests/input/func-calls.c"
void func7(void)
{
  cif_func1 ( );
  func2 ( );
  func3 ( );
  func4 ( );
  func5 ( );
  func6 ( );
}
#line 3 "/home/novikov/work/cif/tests/work/invalid-func-calls.c.aux"
static void cif_func1(void)
{
#line 6 "/home/novikov/work/cif/tests/work/invalid-func-calls.c.aux"
  return;
#line 8 "/home/novikov/work/cif/tests/work/invalid-func-calls.c.aux"
  func1 ( );
}
