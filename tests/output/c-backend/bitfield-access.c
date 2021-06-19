struct A
{
  unsigned char
#line 2 "/home/novikov/work/cif/tests/input/c-backend/bitfield-access.c"
  x : 1U;
};
int func(struct A *a)
{
  if (( * a ) . x != 0U)
    return 0;
#line 9 "/home/novikov/work/cif/tests/input/c-backend/bitfield-access.c"
  return 1;
}
