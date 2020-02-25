static inline __attribute__ ((gnu_inline)) int func(int arg)
{
  return arg;
}

static inline __attribute__ ((gnu_inline)) int gunc(int arg)
{
  return arg;
}

int hunc(int arg)
{
  return func(arg) + gunc(arg);
}
