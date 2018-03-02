#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
typedef struct __va_list_tag __va_list_tag;
#line 1 "input/c-backend/return-void.c"
void func1(void)
{
}
void func2(void)
{
#line 5 "input/c-backend/return-void.c"
  return func1 ( );
}
#line 8 "input/c-backend/return-void.c"
void func3(void)
{
#line 9 "input/c-backend/return-void.c"
  return ({
  } );
}
