void print(char const *);
void func(void)
{
#line 3 "/home/novikov/work/cif/tests/input/c-backend/__func__.c"
  print ( ( char const *) __func__ );
  print ( ( char const *) __FUNCTION__ );
  print ( ( char const *) __PRETTY_FUNCTION__ );
}
