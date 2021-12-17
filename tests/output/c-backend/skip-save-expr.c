void func(long unsigned int arg)
{
  ( void ) ( long unsigned int ) ( __builtin_constant_p ( arg ) == 0 ? -1 : 1 );
}
