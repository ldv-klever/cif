struct b11
{
  int z;
};
#line 4 "/home/novikov/work/cif/tests/input/legacy_type.c"
struct b12
{
  int z;
  int
#line 6 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
};
struct b13
{
  int z;
  int
#line 10 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
  int y;
};
struct b14
{
  int z;
  int
#line 15 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
  int
#line 15 "/home/novikov/work/cif/tests/input/legacy_type.c"
  y;
};
struct b15
{
  int z;
  int
#line 19 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
  double y;
};
struct b21
{
  int z;
  int
#line 24 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
};
struct b22
{
  int z;
  struct b21
#line 28 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
};
struct b23
{
  int z;
  struct b21
#line 32 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
  int y;
};
struct b24
{
  int z;
  int
#line 37 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
  struct b21 y;
};
struct b31
{
  int z;
  int
#line 42 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
};
struct b32
{
  int z;
  struct b31
#line 46 "/home/novikov/work/cif/tests/input/legacy_type.c"
  *x;
};
struct b33
{
  int z;
  struct b31
#line 50 "/home/novikov/work/cif/tests/input/legacy_type.c"
  *x;
  int y;
};
struct b34
{
  int z;
  int
#line 55 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
  struct b31 *y;
};
struct b35
{
  int z;
  int
#line 60 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x;
  struct b35 *y;
};
struct b36
{
  int x;
  struct b36 *y;
  int
#line 68 "/home/novikov/work/cif/tests/input/legacy_type.c"
  z;
};
#line 69 "/home/novikov/work/cif/tests/input/legacy_type.c"
union b41
{
  int z;
  int
#line 71 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x : 1U;
  int y : 2U;
};
union b42
{
  int x : 1U;
  int y : 2U;
  int
#line 79 "/home/novikov/work/cif/tests/input/legacy_type.c"
  z;
};
enum b51
{
  C = 0,
  D = 1,
  A = 2,
  B = 3
};
enum b52
{
  E = 0,
  F = 1,
  G = 2,
  H = 3
};
