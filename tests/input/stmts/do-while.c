int func5(void);
int func6(void);

void func7(int arg)
{
    do {
        func6();
    } while (arg++ != 10 + func5());
}
