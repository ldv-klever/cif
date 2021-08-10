void func(int arg)
{
  __builtin_add_overflow ( arg , 4U , & arg );
}
