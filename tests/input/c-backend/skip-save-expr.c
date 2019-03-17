void func(unsigned long arg)
{
    ((void)sizeof(char[1 - 2*!!(!__builtin_constant_p(arg))]));
}
