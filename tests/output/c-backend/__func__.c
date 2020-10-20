void print(char const *);
void func(void)
{
  print ( ( char const *) __func__ );
  print ( ( char const *) __FUNCTION__ );
  print ( ( char const *) __PRETTY_FUNCTION__ );
}
