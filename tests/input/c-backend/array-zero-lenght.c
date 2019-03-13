struct A
{
    char a;
    char b[0];
};

void func(void *b)
{
    typeof( ((struct A *)0)->b ) *__mptr = b;
}
