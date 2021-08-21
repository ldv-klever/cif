typedef int T1;
typedef unsigned char T2;
#line 4 "/home/novikov/work/cif/tests/input/c-backend/memref-transform2.c"
struct A
{
  T1
#line 5 "/home/novikov/work/cif/tests/input/c-backend/memref-transform2.c"
  a;
  T2 b[4U];
};
#line 7 "/home/novikov/work/cif/tests/input/c-backend/memref-transform2.c"
struct A a;
#line 9 "/home/novikov/work/cif/tests/input/c-backend/memref-transform2.c"
void func(void)
{
#line 10 "/home/novikov/work/cif/tests/input/c-backend/memref-transform2.c"
  int cond = ( ( int ) a . a & 1 ) != 0 && a . b [ 2 ] == 2U && a . b [ 1 ] == 3U;
}
