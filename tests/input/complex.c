void test(int a, int b, int c) {
  int x = __builtin_mul_overflow (a, b, &c);
}
