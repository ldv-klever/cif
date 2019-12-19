#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
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
