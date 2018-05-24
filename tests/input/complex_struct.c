struct A
{
    int a;
    union
    {
        int u;
    }
};

struct A a = { 42, 24 };
