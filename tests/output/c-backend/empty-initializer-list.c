struct A
{
  int
#line 2 "input/c-backend/empty-initializer-list.c"
  a;
};
#line 3 "input/c-backend/empty-initializer-list.c"
struct A a = { };
#line 5 "input/c-backend/empty-initializer-list.c"
void func(void)
{
#line 6 "input/c-backend/empty-initializer-list.c"
  struct A a;
  a = ( struct A ) { };
}
