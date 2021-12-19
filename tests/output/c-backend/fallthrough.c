int func(int arg)
{
  int ret = 0;
#line 5 "/home/siddhartha/work/git/cif/tests/input/c-backend/fallthrough.c"
  switch (arg)
  {
#line 6 "/home/siddhartha/work/git/cif/tests/input/c-backend/fallthrough.c"
    case 1:;
    ret += 10;
#line 9 "/home/siddhartha/work/git/cif/tests/input/c-backend/fallthrough.c"
    case 2:;
    ret += 20;
    break;
    default:;
    break;
  }
#line 16 "/home/siddhartha/work/git/cif/tests/input/c-backend/fallthrough.c"
  return ret;
}
