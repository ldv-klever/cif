#define NOARG
#define ONE_ARG(x) (x)
#define TWO_ARGS(x, y) (x + y)
#define THREE_ARGS(x, y, z) (x + y + z)

int func(void)
{
  return NOARG + ONE_ARG(1) + TWO_ARGS(2, 3) + THREE_ARGS(4, 5, 6);
}
