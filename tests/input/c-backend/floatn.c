_Float32 var1;
_Float32x var2;
_Float64 var3;

#if defined(__x86_64__)
/* GCC for ARM is not aware of these types. */
_Float64x var4;
/* GCC treats __float80 as long double on x86_64. */
__float80 var5;
_Float128 var6;
__float128 var7;
#endif

#if defined(__aarch64__)
/* GCC of ARM 64 knows just these types. */
_Float64x var4;
_Float128 var6;
#endif
