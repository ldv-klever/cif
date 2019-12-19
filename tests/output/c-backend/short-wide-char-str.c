#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
#line 1 "input/c-backend/wide-char-str.c"
short unsigned int var1[14U] = L"Hello, world!";
short unsigned int var2[17U] = L"Здравствуй,\tмир!";
char const var3[14U] = "Hello, world!";
char const var4[31U] = "Здравствуй,\b\nмир!";
