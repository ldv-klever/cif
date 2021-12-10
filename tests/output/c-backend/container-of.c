typedef long unsigned int
#line 4 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
size_t;
#line 6 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
struct A
{
  int x;
  int y;
};
#line 12 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
void func(int *arg)
{
  struct A *a = ({
#line 14 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
    int const *__mptr = arg;
#line 14 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
    ( __mptr + 18446744073709551612U );
  } );
}
