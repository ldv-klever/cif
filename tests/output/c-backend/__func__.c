void print(char const *);
void func(void)
{
#line 3 "/home/novikov/work/cif/tests/input/c-backend/__func__.c"
  print ( __func__ );
  print ( __FUNCTION__ );
  print ( __PRETTY_FUNCTION__ );
}
