int e11;
int cif_set_e11(int);
#line 2 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int cif_get_e11(int);
#line 2 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int e12(int arg)
{
  e11 = cif_set_e11
#line 2 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( arg );
#line 5 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  return cif_get_e11
#line 2 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( e11 );
}
#line 7 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int e13;
int cif_set_e13(int);
#line 8 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int cif_get_e13(int);
#line 8 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int e14(int arg)
{
  e13 = cif_set_e13
#line 8 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( arg );
#line 11 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  return cif_get_e13
#line 8 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( e13 );
}
#line 14 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int cif_get_e16(int);
#line 13 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int e15(int e16)
{
  e16++;
  return cif_get_e16
#line 14 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( e16 );
}
#line 19 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int cif_set_e18(int);
#line 19 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int cif_get_e18(int);
#line 18 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int e17(int arg)
{
  int e18;
  e18 = cif_set_e18
#line 19 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( arg );
#line 22 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  return cif_get_e18
#line 19 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( e18 );
}
#line 25 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int cif_set_e20(int);
#line 25 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int cif_get_e20(int);
#line 24 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
int e19(int arg)
{
  int e20;
  e20 = cif_set_e20
#line 25 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( arg );
#line 28 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  return cif_get_e20
#line 25 "/home/siddhartha/work/git/cif/tests/input/legacy_variable.c"
  ( e20 );
}
#line 1 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
int cif_set_e11(int ldv_var_arg)
{
#line 4 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg++;
#line 6 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  return ldv_var_arg;
}
int cif_get_e11(int ldv_var_arg)
{
#line 11 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg--;
#line 13 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  return ldv_var_arg;
}
int cif_set_e13(int ldv_var_arg)
{
  typedef int ldv_func_ret_type;
#line 19 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_func_ret_type ldv_func_res = ldv_var_arg;
#line 21 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg++;
#line 23 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  return ldv_func_res;
}
int cif_get_e13(int ldv_var_arg)
{
  typedef int ldv_func_ret_type;
#line 29 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_func_ret_type ldv_func_res = ldv_var_arg;
#line 31 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg--;
#line 33 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  return ldv_func_res;
}
int cif_get_e16(int ldv_var_arg)
{
#line 38 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg--;
#line 40 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  return ldv_var_arg;
}
int cif_set_e18(int ldv_var_arg)
{
#line 45 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg++;
#line 47 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  return ldv_var_arg;
}
int cif_get_e18(int ldv_var_arg)
{
#line 52 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg--;
#line 54 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  return ldv_var_arg;
}
int cif_set_e20(int ldv_var_arg)
{
#line 59 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg++;
  return ldv_var_arg;
}
int cif_get_e20(int ldv_var_arg)
{
#line 65 "/home/siddhartha/work/git/cif/tests/work/legacy_variable.c.aux"
  ldv_var_arg--;
  return ldv_var_arg;
}
