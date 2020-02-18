int e11;
int cif_set_e11(int);
#line 4 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int cif_get_e11(int);
#line 6 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int e12(int arg)
{
  e11 = cif_set_e11
#line 2 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( arg );
#line 9 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  return cif_get_e11
#line 4 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( e11 );
}
#line 11 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int e13;
int cif_set_e13(int);
#line 14 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int cif_get_e13(int);
#line 16 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int e14(int arg)
{
  e13 = cif_set_e13
#line 12 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( arg );
#line 19 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  return cif_get_e13
#line 14 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( e13 );
}
#line 22 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int cif_get_e16(int);
int e15(int e16)
{
  e16 ++;
  return cif_get_e16
#line 22 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( e16 );
}
#line 29 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int cif_set_e18(int);
#line 31 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int cif_get_e18(int);
int e17(int arg)
{
  int e18;
  e18 = cif_set_e18
#line 29 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( arg );
#line 36 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  return cif_get_e18
#line 31 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( e18 );
}
#line 39 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int cif_set_e20(int);
#line 41 "/home/novikov/work/cif/tests/input/legacy_kind.c"
int cif_get_e20(int);
int e19(int arg)
{
  int e20;
  e20 = cif_set_e20
#line 39 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( arg );
#line 46 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  return cif_get_e20
#line 41 "/home/novikov/work/cif/tests/input/legacy_kind.c"
  ( e20 );
}
#line 1 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
int cif_set_e11(int ldv_var_arg)
{
#line 4 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
#line 6 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int cif_get_e11(int ldv_var_arg)
{
#line 11 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 13 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int cif_set_e13(int ldv_var_arg)
{
  typedef int ldv_func_ret_type;
#line 19 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_func_ret_type ldv_func_res = ldv_var_arg;
#line 21 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
#line 23 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  return ( int ) ldv_func_res;
}
int cif_get_e13(int ldv_var_arg)
{
  typedef int ldv_func_ret_type;
#line 29 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_func_ret_type ldv_func_res = ldv_var_arg;
#line 31 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 33 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  return ( int ) ldv_func_res;
}
int cif_get_e16(int ldv_var_arg)
{
#line 38 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 40 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int cif_set_e18(int ldv_var_arg)
{
#line 45 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
#line 47 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int cif_get_e18(int ldv_var_arg)
{
#line 52 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
#line 54 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  return ldv_var_arg;
}
int cif_set_e20(int ldv_var_arg)
{
#line 59 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg ++;
  return ldv_var_arg;
}
int cif_get_e20(int ldv_var_arg)
{
#line 65 "/home/novikov/work/cif/tests/work/legacy_kind.c.aux"
  ldv_var_arg --;
  return ldv_var_arg;
}
