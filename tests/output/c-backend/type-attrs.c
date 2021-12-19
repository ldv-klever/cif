struct A
{
  int x;
  int y;
} __attribute__((packed));
#line 7 "/home/siddhartha/work/git/cif/tests/input/c-backend/type-attrs.c"
struct B
{
  int x;
  int y;
} __attribute__((aligned));
#line 13 "/home/siddhartha/work/git/cif/tests/input/c-backend/type-attrs.c"
struct C
{
  int x;
  int y;
} __attribute__((aligned(4)));
#line 19 "/home/siddhartha/work/git/cif/tests/input/c-backend/type-attrs.c"
struct D
{
  int x;
  int y;
} __attribute__((packed)) __attribute__((aligned(4)));
