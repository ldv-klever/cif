#line 2 "/home/siddhartha/work/git/cif/tests/input/c-backend/memref-transform.c"
struct A
{
  unsigned char
#line 3 "/home/siddhartha/work/git/cif/tests/input/c-backend/memref-transform.c"
  x;
  unsigned char y;
} __attribute__((aligned(64)));
extern struct A var;
void func(void)
{
#line 8 "/home/siddhartha/work/git/cif/tests/input/c-backend/memref-transform.c"
  if (var . x == 15U && var . y == 2U)
  {
  }
}
