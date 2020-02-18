struct A
{
  char a;
  char b[0U];
};
#line 7 "/home/novikov/work/cif/tests/input/c-backend/array-zero-lenght.c"
void func(void *b)
{
  char (*__mptr)[0U] = ( char (*)[0U]) b;
}
