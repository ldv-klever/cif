struct A
{
    int a;
    int b;
    union {
        union {
            void (*func)(void);
            void (*gunc)(void);
        };
        void (*hunc)(void);
    };
};

void func(void);
struct A var1 = { .a = 0, .func = func };
struct A var2 = { .a = 0, .gunc = func };
struct A var3 = { .a = 0, .hunc = func };
struct A var4 = { .a = 0, .b = 0 };
struct A var5 = { .a = 0 };
struct A var6 = { .b = 0 };
struct A var7 = { .func = func };
