struct A
{
  unsigned char x;
  unsigned char y;
};
extern struct A var;
void func(void)
{
#line 8 "input/c-backend/memref-transform.c"
  if (var . x == 15U && var . y == 2U)
  {
  }
}
