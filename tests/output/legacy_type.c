struct b11
{
  int z;
};
struct b12
{
  int z;
  int x;
};
struct b13
{
  int z;
  int x;
  int y;
};
struct b14
{
  int z;
  int x;
  int
#line 15 "/home/novikov/work/cif/tests/input/legacy_type.c"
  y;
};
struct b15
{
  int z;
  int x;
  double y;
};
struct b21
{
  int z;
  int x;
};
struct b22
{
  int z;
  struct b21 x;
};
struct b23
{
  int z;
  struct b21 x;
  int y;
};
struct b24
{
  int z;
  int x;
  struct b21 y;
};
struct b31
{
  int z;
  int x;
};
struct b32
{
  int z;
  struct b31 *x;
};
struct b33
{
  int z;
  struct b31 *x;
  int y;
};
struct b34
{
  int z;
  int x;
  struct b31 *y;
};
struct b35
{
  int z;
  int x;
  struct b35 *y;
};
#line 64 "/home/novikov/work/cif/tests/input/legacy_type.c"
union b41
{
  int z;
  int x : 1U;
  int y : 2U;
};
enum b51
{
  C,
  D,
  A = 0,
  B = 1
};
enum b52
{
  E = 0,
  F = 1,
  G,
  H
};
