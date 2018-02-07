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
  int x, y;
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
  int x:1;
  int y:2;
};

enum b51
{
  A,
  B
};
enum b52
{
  E,
  F
};
