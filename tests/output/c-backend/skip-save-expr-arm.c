void func(long unsigned int arg)
{
  ( __builtin_constant_p ( arg ) == 0 ? -1 : 1 );
}
