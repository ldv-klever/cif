#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
typedef struct __va_list_tag __va_list_tag;
struct A
{
  unsigned char
#line 3 "input/c-backend/memref-transform.c"
  x;
  unsigned char y;
};
extern struct A var;
void func(void)
{
#line 8 "input/c-backend/memref-transform.c"
  if (var . x == 15U && var . y == 2U)
  {
  }
}
