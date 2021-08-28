int func(void);
int gunc(void)
{
  int x;
  func ( );
  x = 1;
  int y = 2;
  func ( );
  x = 2;
  int z = func ( );
  func ( );
  x = 3;
  int i = 0;
  x = 4;
#line 16 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  return x + y + z;
}
int hunc(int arg)
{
  int x = 0;
#line 22 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  if (arg == 1)
  {
#line 23 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int y = 2;
    func ( );
    int z = 3;
    x = x + y + z;
  }
  else
  {
    __label__ l;
#line 30 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int y = 3;
    func ( );
    int z;
    z = 4;
    x = x + y + z;
    if (x == 10)
      goto l;
    x += 1;
    l:;
#line 38 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    x += -1;
  }
  {
    int i = 0;
#line 41 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    goto ldv_1336;
    ldv_1335:;
    {
#line 42 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
      int j = i;
      x += j;
      func ( );
      int n = i + j;
    }
#line 41 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    i ++;
    ldv_1336:;
#line 41 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    if (i < arg)
    {
      goto ldv_1335;
    }
    else
      goto ldv_1337;
    ldv_1337:;
  }
#line 48 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  return x;
}
int junc(int arg)
{
#line 53 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  struct A
  {
    int
#line 54 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    x;
    int y;
  };
#line 52 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  int x;
#line 57 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  struct A a = { . x = 1 , . y = 2 };
#line 59 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  if (arg != 0)
  {
    struct B
    {
      int
#line 62 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
      z;
    };
#line 60 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int z = 0;
#line 64 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    func ( );
    struct B b = { . z = 0 };
    x = b . z + z;
  }
#line 69 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  if (arg == 0)
  {
#line 70 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int w = 1001;
  }
#line 73 "/home/novikov/work/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  return x;
}
void iunc(void)
{
  int x;
  int y;
}
