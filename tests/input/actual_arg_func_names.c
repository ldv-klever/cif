void func1();
void func2(void) {
    func1();
}
void func3(int arg1) {
    func2();
}
void func4(void (*arg1)(void)) {
    func3(0);
}
void func5(int arg1, void (*arg2)(void)) {
    func4(func2);
}
void func6(int arg1, void (*arg2)(void), int arg3) {
    func5(arg1, func2);
}
void func7(int arg1, void (*arg2)(void), int arg3, void (*arg4)(int)) {
    func6(arg1, func2, arg3);
}
void func8(int arg1, int arg2) {
    func7(arg1, func2, arg2, func3);
}
