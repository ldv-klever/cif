#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
typedef struct __va_list_tag __va_list_tag;
#line 1 "input/c-backend/fix-trunc-expr.c"
double func(void)
{
#line 2 "input/c-backend/fix-trunc-expr.c"
  return 0.0;
}
#line 5 "input/c-backend/fix-trunc-expr.c"
void main(void)
{
#line 6 "input/c-backend/fix-trunc-expr.c"
  int i = ( int ) func ( );
}
