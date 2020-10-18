struct A
{
  int x;
  int y;
} __attribute__((__packed__));
struct B
{
  int
#line 9 "/home/novikov/work/cif/tests/input/c-backend/type-attrs.c"
  x;
  int y;
} __attribute__((__aligned__));
struct C
{
  int
#line 15 "/home/novikov/work/cif/tests/input/c-backend/type-attrs.c"
  x;
  int y;
} __attribute__((__aligned__(4)));
struct D
{
  int
#line 21 "/home/novikov/work/cif/tests/input/c-backend/type-attrs.c"
  x;
  int y;
} __attribute__((__packed__)) __attribute__((__aligned__(4)));
