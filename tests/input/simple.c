#define SOMETHING
#define CONST 24
#define ZERO(x)  x * 0

struct ST
{
    int x;
};

struct ST st = { 42 };

static int x = 5;

typedef struct ST ST_ST;

int (*func_ptr_global)(int);

static int func(int arg);

int func(int arg) {
    return arg;
}

int main() {
    int a;
    a = 0;

    int b = func(a);

    int c = CONST;

    int (*func_ptr)(int) = &func;

    b = func_ptr(c);
    b = (*func_ptr)(c);

    func_ptr_global = &func;
    x = func_ptr_global(c);

    return ZERO(a + b + c + x);
}
