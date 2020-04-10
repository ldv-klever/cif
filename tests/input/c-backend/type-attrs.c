struct A
{
    int x;
    int y;
} __attribute__((__packed__));

struct B
{
    int x;
    int y;
} __attribute__((__aligned__));

struct C
{
    int x;
    int y;
} __attribute__((__aligned__(4)));

struct D
{
    int x;
    int y;
} __attribute__((__packed__)) __attribute__((__aligned__(4)));
