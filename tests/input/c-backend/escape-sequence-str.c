unsigned char var1[] = "\x90\x00\x06";
unsigned char var2[] = "\40\00\06";
unsigned char var3[] = "\' \" \? \\ \a \b \f \n \r \t \v";

struct A
{
    unsigned char a[3];
};

struct A var4 = {"\x90\x00\x06"};
