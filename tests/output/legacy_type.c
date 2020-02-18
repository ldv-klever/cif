struct b11
{
};
struct b12
{
  int x;
};
struct b13
{
  int x;
  int y;
};
struct b14
{
  int x;
  int
#line 15 "/home/novikov/work/cif/tests/input/legacy_type.c"
  y;
};
struct b15
{
  int x;
  double y;
};
struct b21
{
  int x;
};
struct b22
{
  struct b21 x;
};
struct b23
{
  struct b21 x;
  int y;
};
struct b24
{
  int x;
  struct b21 y;
};
struct b31
{
  int x;
};
struct b32
{
  struct b31 *x;
};
struct b33
{
  struct b31 *x;
  int y;
};
struct b34
{
  int x;
  struct b31 *y;
};
struct b35
{
  int x;
  struct b35 *y;
};
union b41
{
  int
#line 66 "/home/novikov/work/cif/tests/input/legacy_type.c"
  x : 1U;
  int y : 2U;
};
enum b51
{
  A = 0,
  B = 1
};
enum b52
{
  E = 0,
  F = 1
};
