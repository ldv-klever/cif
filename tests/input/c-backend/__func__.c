void print(const char *);
void func(void) {
    print(__func__);
    print(__FUNCTION__);
    print(__PRETTY_FUNCTION__);
}
