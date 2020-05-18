#line 4 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
typedef long unsigned int size_t;
struct A
{
  int
#line 8 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
  x;
  int y;
};
#line 12 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
void func(int *arg)
{
  struct A *a = ({
#line 14 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
    int const *__mptr = ( int const *) arg;
#line 14 "/home/novikov/work/cif/tests/input/c-backend/container-of.c"
    ( struct A *) ( ( char *) __mptr + 18446744073709551612U );
  } );
}
