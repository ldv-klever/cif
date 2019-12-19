#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
#line 1 "input/c-backend/memref-transform2.c"
typedef int T1;
typedef unsigned char T2;
struct A
{
  T1 a;
  T2 b[4U];
};
#line 7 "input/c-backend/memref-transform2.c"
struct A a;
#line 9 "input/c-backend/memref-transform2.c"
void func(void)
{
#line 10 "input/c-backend/memref-transform2.c"
  int cond = ( ( int ) a . a & 1 ) != 0 && a . b [ 2 ] == 2U && a . b [ 1 ] == 3U;
}
