#define A 100
#define BC 200
#define X(x) (x + 1)
#define YZ(y, z) (y * z)
#define PRINTF(fmt, ...) printf(fmt, ##__VA_ARGS__)

int printf(const char *format, ...);

int func(void)
{
    PRINTF("Hello, %s", "world");
    return X(A) + YZ(A, BC);
}
