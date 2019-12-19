#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
#line 40 "/home/novikov/work/cif/bin/aspectator-bin/lib64/gcc/x86_64-pc-linux-gnu/7.5.0/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
#line 99 "/home/novikov/work/cif/bin/aspectator-bin/lib64/gcc/x86_64-pc-linux-gnu/7.5.0/include/stdarg.h"
typedef __gnuc_va_list va_list;
#line 3 "input/va-funcs.c"
void func(int, ...);
void gunc(char const *, ...);
void hunc(char const *, va_list);
#line 7 "input/va-funcs.c"
int iunc(int arg1, char const *arg2, ...)
{
  va_list args;
#line 11 "input/va-funcs.c"
  func ( arg1 );
  gunc ( arg2 );
  __builtin_va_start ( args , arg2 );
  hunc ( arg2 , args );
  __builtin_va_end ( args );
}
