struct A
{
  unsigned char x;
  unsigned char y;
} __attribute__((__aligned__(64)));
extern struct A var;
void func(void)
{
#line 8 "/home/novikov/work/cif/tests/input/c-backend/memref-transform.c"
  if (var . x == 15U && var . y == 2U)
  {
  }
}
