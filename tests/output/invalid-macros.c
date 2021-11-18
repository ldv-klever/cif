#line 7 "/home/novikov/work/cif/tests/input/macros.c"
int printf(char const *, ...);
#line 9 "/home/novikov/work/cif/tests/input/macros.c"
int func(void)
{
  printf ( ( char const *) "Hello, %s" , ( char *) "world" );
  return 20101;
}
