struct A {
    unsigned char x : 1;
};
int func(struct A *a)
{
    if (a->x)
        return 0;
    
    return 1;
}
