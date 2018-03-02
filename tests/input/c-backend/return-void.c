void func1(void) {
}

void func2(void) {
    return func1();
}

void func3(void) {
    return ({;});
}
