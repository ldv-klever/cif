/* Source code is based on https://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html. */
typedef int v4si __attribute__ ((vector_size (16)));

void func(void)
{
    v4si a, b, c, d, e, g = {1,2,3,4}, h = {3,2,1,4}, i;

    c = a + b;

    d = e + 1;    /* d = e + {1,1,1,1}; */
    d = 2 * e;    /* d = {2,2,2,2} * e; */

    i = g >  h;     /* The result would be {0, 0,-1, 0}  */
    i = g == h;     /* The result would be {0,-1, 0,-1}  */
}
