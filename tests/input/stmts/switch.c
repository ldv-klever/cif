void func1(void);
void func2(void);
void func3(void);
int func5(void);
int func6(void);

void func7(int arg)
{
    switch (func5() + arg) {
        case 3:
            func3();
            break;
        case 5:
            func1();
        case 6:
            func6();
            break;
        default:
            func2();
    }
}
