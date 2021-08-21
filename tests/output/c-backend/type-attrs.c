struct A
{
  int x;
  int y;
} __attribute__((__packed__));
#line 7 "/home/novikov/work/cif/tests/input/c-backend/type-attrs.c"
struct B
{
  int x;
  int y;
} __attribute__((__aligned__));
#line 13 "/home/novikov/work/cif/tests/input/c-backend/type-attrs.c"
struct C
{
  int x;
  int y;
} __attribute__((__aligned__(4)));
#line 19 "/home/novikov/work/cif/tests/input/c-backend/type-attrs.c"
struct D
{
  int x;
  int y;
} __attribute__((__packed__)) __attribute__((__aligned__(4)));
