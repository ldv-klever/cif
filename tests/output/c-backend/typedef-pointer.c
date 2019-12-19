#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
#line 1 "input/c-backend/typedef-pointer.c"
typedef int T1;
typedef int *T2;
typedef T2 T3;
typedef T2 *T4;
T1 var1;
T2 var2;
T3 var3;
T4 var4;
T1 *var5;
T2 *var6;
T3 *var7;
T4 *var8;
void func(T1, T2, T1 *, T2 *, T1 **, T2 **);
void gunc(T1 arg1, T2 arg2, T1 *arg3, T2 *arg4, T1 **arg5, T2 **arg6)
{
}
