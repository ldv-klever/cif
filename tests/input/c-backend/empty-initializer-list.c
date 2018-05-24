struct A {
    int a;
} a = (struct A){};

void func(void) {
    struct A a;
    a = (struct A){};
}

