void func(int arg)
{
    __builtin_add_overflow(arg, sizeof(int), &arg);
}
