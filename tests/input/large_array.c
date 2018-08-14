#define ARRAY_SIZE (1L << 20)
int *array[ARRAY_SIZE] = {
    [0 ... ARRAY_SIZE - 1] = (void *)0
};
