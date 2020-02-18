struct A
{
  int
#line 2 "/home/novikov/work/cif/tests/input/c-backend/empty-initializer-list.c"
  a;
};
#line 3 "/home/novikov/work/cif/tests/input/c-backend/empty-initializer-list.c"
struct A a = { };
#line 5 "/home/novikov/work/cif/tests/input/c-backend/empty-initializer-list.c"
void func(void)
{
#line 6 "/home/novikov/work/cif/tests/input/c-backend/empty-initializer-list.c"
  struct A a;
  a = ( struct A ) { };
}
