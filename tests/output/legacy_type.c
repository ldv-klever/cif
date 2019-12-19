#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
struct b11
{
};
struct b12
{
  int
#line 6 "input/legacy_type.c"
  x;
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
#line 15 "input/legacy_type.c"
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
#line 66 "input/legacy_type.c"
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
