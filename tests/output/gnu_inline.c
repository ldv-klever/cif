static inline int cif_func(int arg)
{
  return arg;
}
#line 7 "/home/novikov/work/cif/tests/input/gnu_inline.c"
static inline int cif_func(int);
#line 1 "/home/novikov/work/cif/tests/input/gnu_inline.c"
static inline int func(int arg);
#line 6 "/home/novikov/work/cif/tests/input/gnu_inline.c"
static inline int gunc(int arg)
{
  return arg;
}
#line 6 "/home/novikov/work/cif/tests/input/gnu_inline.c"
static inline int gunc(int arg);
#line 12 "/home/novikov/work/cif/tests/input/gnu_inline.c"
static inline int cif_gunc(int);
#line 11 "/home/novikov/work/cif/tests/input/gnu_inline.c"
int hunc(int arg)
{
  return func ( arg ) + cif_gunc ( arg );
}
#line 3 "/home/novikov/work/cif/tests/work/gnu_inline.c.aux"
static inline int func(int arg)
{
#line 7 "/home/novikov/work/cif/tests/work/gnu_inline.c.aux"
  return cif_func ( arg );
}
#line 11 "/home/novikov/work/cif/tests/work/gnu_inline.c.aux"
static inline int cif_gunc(int arg)
{
#line 15 "/home/novikov/work/cif/tests/work/gnu_inline.c.aux"
  return gunc ( arg );
}
