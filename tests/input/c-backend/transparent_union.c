struct A;
typedef union { struct A *a; } c __attribute__ ((__transparent_union__));
  
void gunc(c);

void func(struct A *a) {
    gunc(a);
}
