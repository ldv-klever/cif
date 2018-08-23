struct A
{
    int a;
    union
    {
        int u;
    };
};

struct A a = { 42, 24 };

struct A b = {};

struct A c[] = { { 21, 12 }, {} };

struct B
{
    struct A b;
};

struct B d = { {} };
