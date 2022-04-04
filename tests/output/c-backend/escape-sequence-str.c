unsigned char var1[4U] = "\x90\x00\x06";
unsigned char var2[4U] = "\40\00\06";
unsigned char var3[22U] = "\' \" \? \\ \a \b \f \n \r \t \v";
#line 5 "/home/novikov/work/cif/tests/input/c-backend/escape-sequence-str.c"
struct A
{
  unsigned char a[3U];
};
#line 10 "/home/novikov/work/cif/tests/input/c-backend/escape-sequence-str.c"
struct A var4 = { . a = "\x90\x00\x06" };
