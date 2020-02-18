struct A;
typedef union
{
  struct A
#line 2 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
  *a;
} c;
void gunc(c);
#line 6 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
void func(struct A *a)
{
#line 7 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
  gunc ( a );
}
