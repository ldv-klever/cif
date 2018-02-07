#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
typedef struct __va_list_tag __va_list_tag;
#line 1 "tests/input/legacy_kind.c"
int e11;
int ldv_e11_1(int);
#line 4 "tests/input/legacy_kind.c"
int ldv_e11_2(int);
#line 6 "tests/input/legacy_kind.c"
int e12(int arg)
{
  e11 = ldv_e11_1
#line 2 "tests/input/legacy_kind.c"
  ( arg );
#line 9 "tests/input/legacy_kind.c"
  return ldv_e11_2
#line 4 "tests/input/legacy_kind.c"
  ( e11 );
}
#line 11 "tests/input/legacy_kind.c"
int e13;
int ldv_e13_3(int);
#line 14 "tests/input/legacy_kind.c"
int ldv_e13_4(int);
#line 16 "tests/input/legacy_kind.c"
int e14(int arg)
{
  e13 = ldv_e13_3
#line 12 "tests/input/legacy_kind.c"
  ( arg );
#line 19 "tests/input/legacy_kind.c"
  return ldv_e13_4
#line 14 "tests/input/legacy_kind.c"
  ( e13 );
}
#line 22 "tests/input/legacy_kind.c"
int ldv_e16_5(int);
int e15(int e16)
{
  e16 ++;
  return ldv_e16_5
#line 22 "tests/input/legacy_kind.c"
  ( e16 );
}
#line 29 "tests/input/legacy_kind.c"
int ldv_e18_6(int);
#line 31 "tests/input/legacy_kind.c"
int ldv_e18_7(int);
int e17(int arg)
{
  int e18;
  e18 = ldv_e18_6
#line 29 "tests/input/legacy_kind.c"
  ( arg );
#line 36 "tests/input/legacy_kind.c"
  return ldv_e18_7
#line 31 "tests/input/legacy_kind.c"
  ( e18 );
}
#line 39 "tests/input/legacy_kind.c"
int ldv_e20_8(int);
#line 41 "tests/input/legacy_kind.c"
int ldv_e20_9(int);
int e19(int arg)
{
  int e20;
  e20 = ldv_e20_8
#line 39 "tests/input/legacy_kind.c"
  ( arg );
#line 46 "tests/input/legacy_kind.c"
  return ldv_e20_9
#line 41 "tests/input/legacy_kind.c"
  ( e20 );
}
#line 1 "tests/work/legacy_kind.c.aux"
int ldv_e11_1(int ldv_var_arg)
{
#line 4 "tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
#line 6 "tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int ldv_e11_2(int ldv_var_arg)
{
#line 11 "tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 13 "tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int ldv_e13_3(int ldv_var_arg)
{
  typedef int ldv_func_ret_type;
#line 19 "tests/work/legacy_kind.c.aux"
  ldv_func_ret_type ldv_func_res = ldv_var_arg;
#line 21 "tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
#line 23 "tests/work/legacy_kind.c.aux"
  return ( int ) ldv_func_res;
}
int ldv_e13_4(int ldv_var_arg)
{
  typedef int ldv_func_ret_type;
#line 29 "tests/work/legacy_kind.c.aux"
  ldv_func_ret_type ldv_func_res = ldv_var_arg;
#line 31 "tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 33 "tests/work/legacy_kind.c.aux"
  return ( int ) ldv_func_res;
}
int ldv_e16_5(int ldv_var_arg)
{
#line 38 "tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 40 "tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int ldv_e18_6(int ldv_var_arg)
{
#line 45 "tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
#line 47 "tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int ldv_e18_7(int ldv_var_arg)
{
#line 52 "tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 54 "tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int ldv_e20_8(int ldv_var_arg)
{
#line 59 "tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
  return ldv_var_arg;
}
int ldv_e20_9(int ldv_var_arg)
{
#line 65 "tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
  return ldv_var_arg;
}
