void func(long unsigned int arg)
{
  ( void ) ( __builtin_constant_p ( arg ) == 0 ? -1 : 1 );
}
