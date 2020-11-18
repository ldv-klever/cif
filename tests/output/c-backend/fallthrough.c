int func(int arg)
{
  int ret = 0;
#line 5 "/home/novikov/work/cif/tests/input/c-backend/fallthrough.c"
  switch (arg)
  {
#line 6 "/home/novikov/work/cif/tests/input/c-backend/fallthrough.c"
    case 1:;
    ret += 10;
#line 9 "/home/novikov/work/cif/tests/input/c-backend/fallthrough.c"
    case 2:;
    ret += 20;
    goto ldv_1;
    default:;
    goto ldv_1;
  }
#line 16 "/home/novikov/work/cif/tests/input/c-backend/fallthrough.c"
  ldv_1:;
#line 16 "/home/novikov/work/cif/tests/input/c-backend/fallthrough.c"
  return ret;
}
