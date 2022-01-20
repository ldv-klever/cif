int get_property(const char *);
void set_property(const char *, int);

void func(void)
{
    int prop1_val, prop2_val;
    const char *prop1 = "prop1", *prop2 = "prop2";
    
    prop1_val = get_property(prop1);
    set_property(prop1, 1);

    prop2_val = get_property(prop2);
    set_property(prop2, 2);
}
