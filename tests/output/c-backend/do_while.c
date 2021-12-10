int func(void)
{
  int x = 0;
#line 5 "/home/novikov/work/cif-gcc-11/tests/input/c-backend/do_while.c"
  do
  {
#line 6 "/home/novikov/work/cif-gcc-11/tests/input/c-backend/do_while.c"
    x++;
    continue;
  }  while (x != 1);
}
