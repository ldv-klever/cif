#line 40 "/home/novikov/work/cif/inst/cif/lib64/gcc/x86_64-pc-linux-gnu/7.5.0/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
#line 99 "/home/novikov/work/cif/inst/cif/lib64/gcc/x86_64-pc-linux-gnu/7.5.0/include/stdarg.h"
typedef __gnuc_va_list va_list;
#line 3 "/home/novikov/work/cif/tests/input/va-funcs.c"
void func(int, ...);
void gunc(char const *, ...);
void hunc(char const *, va_list);
#line 7 "/home/novikov/work/cif/tests/input/va-funcs.c"
void iunc(int arg1, char const *arg2, ...)
{
  va_list args;
#line 11 "/home/novikov/work/cif/tests/input/va-funcs.c"
  func ( arg1 );
  gunc ( arg2 );
  __builtin_va_start ( args , arg2 );
  hunc ( arg2 , args );
  __builtin_va_end ( args );
}
#line 18 "/home/novikov/work/cif/tests/input/va-funcs.c"
void junc(int arg, va_list va)
{
  func ( arg , va );
}
