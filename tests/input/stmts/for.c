void func1(void);
int func4(void);
int func5(void);
int func6(void);

void func7(int arg)
{
    for (int i = func4(); i < func5(); i += func6()) {
        for (int j = func6(); j > func5(); j -= func4())
            func1();
        
        if (i == arg)
            continue;
        if (i == -arg)
            break;
    }
}
