struct A;
typedef union
{
  struct A
#line 2 "input/c-backend/transparent_union.c"
  *a;
} c;
void gunc(c);
#line 6 "input/c-backend/transparent_union.c"
void func(struct A *a)
{
#line 7 "input/c-backend/transparent_union.c"
  gunc ( a );
}
