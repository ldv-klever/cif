struct A
{
  int a;
  int b;
  union
  {
#line 6 "/home/novikov/work/cif/tests/input/c-backend/anonymous-union-init.c"
    union
    {
      void
#line 7 "/home/novikov/work/cif/tests/input/c-backend/anonymous-union-init.c"
      (*func)(void);
      void (*gunc)(void);
    };
    void (*hunc)(void);
  };
};
#line 14 "/home/novikov/work/cif/tests/input/c-backend/anonymous-union-init.c"
void func(void);
struct A var1 = { . a = 0 , . func = & func };
struct A var2 = { . a = 0 , . gunc = & func };
struct A var3 = { . a = 0 , . hunc = & func };
struct A var4 = { . a = 0 , . b = 0 };
struct A var5 = { . a = 0 };
struct A var6 = { . b = 0 };
struct A var7 = { . func = & func };
