/* Macro and type definitions like in the Linux kernel. */
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({ const typeof( ((type *)0)->member ) *__mptr = (ptr); (type *)( (char *)__mptr - offsetof(type,member) );})
typedef unsigned long size_t;

struct A
{
  int x;
  int y;
};

void func(int *arg)
{
  struct A *a = container_of(arg, struct A, y);
}
