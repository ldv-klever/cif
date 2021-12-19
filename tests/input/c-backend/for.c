int func()
{
    int j;

    for (j = 0; ; )
        break;

    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
            break;
    }

    for (;;) {}

    for (;;);
}
