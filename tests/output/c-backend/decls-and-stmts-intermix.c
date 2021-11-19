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
#line 16 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  return x + y + z;
}
int hunc(int arg)
{
  int x = 0;
#line 22 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  if (arg == 1)
  {
#line 23 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int y = 2;
    func ( );
    int z = 3;
    x = x + y + z;
  }
  else
  {
    __label__ l;
#line 30 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int y = 3;
    func ( );
    int z;
    z = 4;
    x = x + y + z;
    if (x == 10)
    {
#line 36 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
      goto l;
    }
#line 37 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    x += 1;
    l:;
#line 38 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    x += -1;
  }
  {
    int i = 0;
#line 41 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    for ( ; i < arg ; i++)
    {
#line 42 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
      int j = i;
      x += j;
      func ( );
      int n = i + j;
    }
  }
  return x;
}
int junc(int arg)
{
#line 53 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  struct A
  {
    int
#line 54 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    x;
    int y;
  };
#line 52 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  int x;
#line 57 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  struct A a = { . x = 1 , . y = 2 };
#line 59 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  if (arg != 0)
  {
    struct B
    {
      int
#line 62 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
      z;
    };
#line 60 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int z = 0;
#line 64 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    func ( );
    struct B b = { . z = 0 };
    x = b . z + z;
  }
#line 69 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  if (arg == 0)
  {
#line 70 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
    int w = 1001;
  }
#line 73 "/home/siddhartha/work/git/cif/tests/input/c-backend/decls-and-stmts-intermix.c"
  return x;
}
void iunc(void)
{
  int x;
  int y;
}
