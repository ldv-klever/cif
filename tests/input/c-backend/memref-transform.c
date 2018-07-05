
struct A {
    unsigned char x;
    unsigned char y;
} __attribute__((__aligned__((1 << (6)))));
extern struct A var;
void func(void) {
    if (var.x == 0x0F && var.y == 2) {}
}
