int func(unsigned int nr, const unsigned long *addr)
{
    unsigned long *a = (unsigned long *)addr + nr / 64;

    return 0;
}
