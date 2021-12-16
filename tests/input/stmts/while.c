void func2(void);
int func5(void);

void func7(int arg)
{
    while (func5() + arg--)
        func2();
}
