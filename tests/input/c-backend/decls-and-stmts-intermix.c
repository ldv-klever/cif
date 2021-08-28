int func(void);
int gunc(void)
{
    int x;
    func();
    x = 1;
    int y = 2;
    func();
    x = 2;
    int z = func();
    func();
    x = 3;
    int i = 0;
    x = 4;

    return x + y + z;
}
int hunc(int arg)
{
    int x = 0;

    if (arg == 1) {
        int y = 2;
        func();
        int z = 3;
        x = x + y + z;
    }
    else {
        __label__ l;
        int y = 3;
        func();
        int z;
        z = 4;
        x = x + y + z;
        if (x == 10)
            goto l;
        x += 1;
        l: x -= 1;
    }

    for (int i = 0; i < arg; i++) {
        int j = i;
        x += j;
        func();
        int n = i + j;
    }

    return x;
}
int junc(int arg)
{
    int x;
    struct A {
        int x;
        int y;
    };
    struct A a = {1, 2};

    if (arg) {
        int z = 0;
        struct B {
            int z;
        };
        func();
        struct B b = {0};
        x = z + b.z;
    }

    if (!arg) {
        int w = 1001;
    }

    return x;
}
void iunc(void)
{
    int x;
    int y;
}
