#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
struct A
{
  char
#line 3 "input/c-backend/array-zero-lenght.c"
  a;
  char b[0U];
};
#line 7 "input/c-backend/array-zero-lenght.c"
void func(void *b)
{
  char (*__mptr)[0U] = ( char (*)[0U]) b;
}
