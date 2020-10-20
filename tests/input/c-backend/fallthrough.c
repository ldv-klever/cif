int func(int arg)
{
    int ret = 0;

    switch (arg) {
        case 1:
            ret += 10;
            __attribute__((__fallthrough__));
        case 2:
            ret += 20;
            break;
        default:
            break;
    }

    return ret;
}
