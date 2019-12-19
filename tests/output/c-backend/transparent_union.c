#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
struct A;
#line 2 "input/c-backend/transparent_union.c"
typedef union
{
  struct A
#line 2 "input/c-backend/transparent_union.c"
  *a;
} c;
void gunc(c);
#line 6 "input/c-backend/transparent_union.c"
void func(struct A *a)
{
#line 7 "input/c-backend/transparent_union.c"
  gunc ( a );
}
