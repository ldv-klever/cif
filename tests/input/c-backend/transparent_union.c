struct A;
typedef union { struct A *a; } c __attribute__ ((__transparent_union__));
union B { struct A *a; } __attribute__ ((__transparent_union__));

void gunc(c);

void func(struct A *a) {
    gunc(a);
}
