#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
typedef struct __va_list_tag __va_list_tag;
#line 1 "input/legacy_macro.c"
int one(void)
{
  return 1;
}
int two(void)
{
  return 2;
}
int three(void)
{
  return 3;
}
int four(void)
{
  return 4;
}
int sixth(void)
{
  return 6;
}
int seventh(int a, int b)
{
  return a + b;
}
#line 1 "input/legacy_macro.h"
int five(void)
{
  return 5;
}
