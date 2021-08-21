struct A;
typedef union
{
  struct A
#line 2 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
  *a;
} __attribute__((__transparent_union__))
#line 2 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
c;
union B
{
  struct A
#line 3 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
  *a;
} __attribute__((__transparent_union__));
void gunc(c);
#line 7 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
void func(struct A *a)
{
#line 8 "/home/novikov/work/cif/tests/input/c-backend/transparent_union.c"
  gunc ( a );
}
