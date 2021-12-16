void func1(void);
void func2(void);
void func3(void);
int func5(void);
int func6(void);

void func7(int arg)
{
    if (func5() != arg)
        func1();
    else if (func6() != -arg)
        func2();
    else
        func3();
}
