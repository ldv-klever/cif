#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
#line 1 "input/aux-funcs.c"
int func(void);
int func(void);
#line 4 "input/aux-funcs.c"
static int cif_func(void);
#line 7 "input/aux-funcs.c"
int gunc(void)
{
  cif_func ( );
  cif_func ( );
}
#line 3 "work/aux-funcs.c.aux"
static int cif_func(void)
{
#line 6 "work/aux-funcs.c.aux"
  return 1;
#line 8 "work/aux-funcs.c.aux"
  return cif_func ( );
}
