typedef int T1;
typedef unsigned char T2;

struct A {
    T1 a;
    T2 b[4];
} a;

void func(void) {
    int cond = ((a.a & 1) && (a.b[2] == 2) && (a.b[1] == 3));
}
