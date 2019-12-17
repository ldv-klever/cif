#define LDV_MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define LDV_MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define LDV_ABS(X) ((X) < 0 ? -(X) : (X))
#define LDV_LROTATE(X,Y) (((X) << (Y)) | ((X) >> (__CHAR_BIT__ * sizeof (X) - Y)))
#define LDV_RROTATE(X,Y) (((X) >> (Y)) | ((X) << (__CHAR_BIT__ * sizeof (X) - Y)))
typedef struct __va_list_tag __va_list_tag;
#line 1 "input/legacy_function.c"
void cif_a011(int arg)
{
}
#line 5 "input/legacy_function.c"
void cif_a011(int);
#line 1 "input/legacy_function.c"
void a011(int arg);
#line 8 "input/legacy_function.c"
void cif_a012(int arg)
{
}
#line 12 "input/legacy_function.c"
void cif_a012(int);
#line 8 "input/legacy_function.c"
void a012(int arg);
#line 15 "input/legacy_function.c"
void cif_a013(long long unsigned int const arg)
{
}
#line 19 "input/legacy_function.c"
void cif_a013(long long unsigned int const);
#line 15 "input/legacy_function.c"
void a013(long long unsigned int const arg);
#line 22 "input/legacy_function.c"
void cif_a014(long double arg)
{
}
#line 27 "input/legacy_function.c"
void cif_a014(long double);
#line 22 "input/legacy_function.c"
void a014(long double arg);
#line 30 "input/legacy_function.c"
void *cif_a020(int *arg)
{
  return ( ( void *) 0 );
}
#line 35 "input/legacy_function.c"
void *cif_a020(int *);
#line 30 "input/legacy_function.c"
void *a020(int *arg);
#line 38 "input/legacy_function.c"
void cif_a021(int *arg)
{
}
#line 42 "input/legacy_function.c"
void cif_a021(int *);
#line 38 "input/legacy_function.c"
void a021(int *arg);
#line 45 "input/legacy_function.c"
void cif_a022(int *arg)
{
}
#line 49 "input/legacy_function.c"
void cif_a022(int *);
#line 45 "input/legacy_function.c"
void a022(int *arg);
#line 52 "input/legacy_function.c"
void cif_a023(int *const *volatile arg)
{
}
#line 56 "input/legacy_function.c"
void cif_a023(int *const *volatile);
#line 52 "input/legacy_function.c"
void a023(int *const *volatile arg);
#line 59 "input/legacy_function.c"
void cif_a024(int *const *volatile arg)
{
}
#line 64 "input/legacy_function.c"
void cif_a024(int *const *volatile);
#line 59 "input/legacy_function.c"
void a024(int *const *volatile arg);
#line 67 "input/legacy_function.c"
void cif_a031(int *arg)
{
}
#line 71 "input/legacy_function.c"
void cif_a031(int *);
#line 67 "input/legacy_function.c"
void a031(int *arg);
#line 74 "input/legacy_function.c"
void cif_a032(int *arg)
{
}
#line 78 "input/legacy_function.c"
void cif_a032(int *);
#line 74 "input/legacy_function.c"
void a032(int *arg);
#line 81 "input/legacy_function.c"
void cif_a033(int (*arg)[20U][30U])
{
}
#line 85 "input/legacy_function.c"
void cif_a033(int (*)[20U][30U]);
#line 81 "input/legacy_function.c"
void a033(int (*arg)[20U][30U]);
#line 88 "input/legacy_function.c"
void cif_a034(int (*arg)[20U][30U])
{
}
#line 93 "input/legacy_function.c"
void cif_a034(int (*)[20U][30U]);
#line 88 "input/legacy_function.c"
void a034(int (*arg)[20U][30U]);
#line 96 "input/legacy_function.c"
void cif_a041(int **arg)
{
}
#line 100 "input/legacy_function.c"
void cif_a041(int **);
#line 96 "input/legacy_function.c"
void a041(int **arg);
#line 103 "input/legacy_function.c"
void cif_a042(int **arg)
{
}
#line 107 "input/legacy_function.c"
void cif_a042(int **);
#line 103 "input/legacy_function.c"
void a042(int **arg);
#line 110 "input/legacy_function.c"
void cif_a043(int *const *volatile (*arg)[20U][30U])
{
}
#line 114 "input/legacy_function.c"
void cif_a043(int *const *volatile (*)[20U][30U]);
#line 110 "input/legacy_function.c"
void a043(int *const *volatile (*arg)[20U][30U]);
#line 117 "input/legacy_function.c"
void cif_a044(int *const *volatile (*arg)[20U][30U])
{
}
#line 122 "input/legacy_function.c"
void cif_a044(int *const *volatile (*)[20U][30U]);
#line 117 "input/legacy_function.c"
void a044(int *const *volatile (*arg)[20U][30U]);
#line 125 "input/legacy_function.c"
void cif_a051(int (*arg)[10U])
{
}
#line 129 "input/legacy_function.c"
void cif_a051(int (*)[10U]);
#line 125 "input/legacy_function.c"
void a051(int (*arg)[10U]);
#line 132 "input/legacy_function.c"
void cif_a052(int (*arg)[10U])
{
}
#line 136 "input/legacy_function.c"
void cif_a052(int (*)[10U]);
#line 132 "input/legacy_function.c"
void a052(int (*arg)[10U]);
#line 139 "input/legacy_function.c"
void cif_a053(int (*const *volatile arg)[10U][20U][30U])
{
}
#line 143 "input/legacy_function.c"
void cif_a053(int (*const *volatile)[10U][20U][30U]);
#line 139 "input/legacy_function.c"
void a053(int (*const *volatile arg)[10U][20U][30U]);
#line 146 "input/legacy_function.c"
void cif_a054(int (*const *volatile arg)[10U][20U][30U])
{
}
#line 151 "input/legacy_function.c"
void cif_a054(int (*const *volatile)[10U][20U][30U]);
#line 146 "input/legacy_function.c"
void a054(int (*const *volatile arg)[10U][20U][30U]);
#line 154 "input/legacy_function.c"
void cif_a061(int **(*arg)[10U])
{
}
#line 158 "input/legacy_function.c"
void cif_a061(int **(*)[10U]);
#line 154 "input/legacy_function.c"
void a061(int **(*arg)[10U]);
#line 161 "input/legacy_function.c"
void cif_a062(int **(*arg)[10U])
{
}
#line 165 "input/legacy_function.c"
void cif_a062(int **(*)[10U]);
#line 161 "input/legacy_function.c"
void a062(int **(*arg)[10U]);
#line 168 "input/legacy_function.c"
void cif_a063(int *const *volatile (*const *volatile arg)[10U][20U][30U])
{
}
#line 172 "input/legacy_function.c"
void cif_a063(int *const *volatile (*const *volatile)[10U][20U][30U]);
#line 168 "input/legacy_function.c"
void a063(int *const *volatile (*const *volatile arg)[10U][20U][30U]);
#line 175 "input/legacy_function.c"
void cif_a064(int *const *volatile (*const *volatile arg)[10U][20U][30U])
{
}
#line 180 "input/legacy_function.c"
void cif_a064(int *const *volatile (*const *volatile)[10U][20U][30U]);
#line 175 "input/legacy_function.c"
void a064(int *const *volatile (*const *volatile arg)[10U][20U][30U]);
#line 183 "input/legacy_function.c"
void cif_a071(int (*arg)(void))
{
}
#line 187 "input/legacy_function.c"
void cif_a071(int (*)(void));
#line 183 "input/legacy_function.c"
void a071(int (*arg)(void));
#line 190 "input/legacy_function.c"
void cif_a072(int (*arg)(void))
{
}
#line 194 "input/legacy_function.c"
void cif_a072(int (*)(void));
#line 190 "input/legacy_function.c"
void a072(int (*arg)(void));
#line 197 "input/legacy_function.c"
void cif_a073(int (*const arg)(void))
{
}
#line 201 "input/legacy_function.c"
void cif_a073(int (*const)(void));
#line 197 "input/legacy_function.c"
void a073(int (*const arg)(void));
#line 204 "input/legacy_function.c"
void cif_a074(int (*const arg)(void))
{
}
#line 209 "input/legacy_function.c"
void cif_a074(int (*const)(void));
#line 204 "input/legacy_function.c"
void a074(int (*const arg)(void));
#line 212 "input/legacy_function.c"
void cif_a081(int **(*arg)(void))
{
}
#line 216 "input/legacy_function.c"
void cif_a081(int **(*)(void));
#line 212 "input/legacy_function.c"
void a081(int **(*arg)(void));
#line 219 "input/legacy_function.c"
void cif_a082(int **(*arg)(void))
{
}
#line 223 "input/legacy_function.c"
void cif_a082(int **(*)(void));
#line 219 "input/legacy_function.c"
void a082(int **(*arg)(void));
#line 226 "input/legacy_function.c"
void cif_a083(int *const *volatile *(*const arg)(void))
{
}
#line 230 "input/legacy_function.c"
void cif_a083(int *const *volatile *(*const)(void));
#line 226 "input/legacy_function.c"
void a083(int *const *volatile *(*const arg)(void));
#line 233 "input/legacy_function.c"
void cif_a084(int *const *volatile *(*const arg)(void))
{
}
#line 238 "input/legacy_function.c"
void cif_a084(int *const *volatile *(*const)(void));
#line 233 "input/legacy_function.c"
void a084(int *const *volatile *(*const arg)(void));
#line 241 "input/legacy_function.c"
void cif_a091(int (**arg)(void))
{
}
#line 245 "input/legacy_function.c"
void cif_a091(int (**)(void));
#line 241 "input/legacy_function.c"
void a091(int (**arg)(void));
#line 248 "input/legacy_function.c"
void cif_a092(int (**arg)(void))
{
}
#line 252 "input/legacy_function.c"
void cif_a092(int (**)(void));
#line 248 "input/legacy_function.c"
void a092(int (**arg)(void));
#line 255 "input/legacy_function.c"
void cif_a093(int (*const (*arg)[20U][30U])(void))
{
}
#line 259 "input/legacy_function.c"
void cif_a093(int (*const (*)[20U][30U])(void));
#line 255 "input/legacy_function.c"
void a093(int (*const (*arg)[20U][30U])(void));
#line 262 "input/legacy_function.c"
void cif_a094(int (*const (*arg)[20U][30U])(void))
{
}
#line 267 "input/legacy_function.c"
void cif_a094(int (*const (*)[20U][30U])(void));
#line 262 "input/legacy_function.c"
void a094(int (*const (*arg)[20U][30U])(void));
#line 270 "input/legacy_function.c"
void cif_a101(int **(**arg)(void))
{
}
#line 274 "input/legacy_function.c"
void cif_a101(int **(**)(void));
#line 270 "input/legacy_function.c"
void a101(int **(**arg)(void));
#line 277 "input/legacy_function.c"
void cif_a102(int **(**arg)(void))
{
}
#line 281 "input/legacy_function.c"
void cif_a102(int **(**)(void));
#line 277 "input/legacy_function.c"
void a102(int **(**arg)(void));
#line 284 "input/legacy_function.c"
void cif_a103(int *const *volatile *(*const *const volatile *(*arg)[20U][30U])(void))
{
}
#line 288 "input/legacy_function.c"
void cif_a103(int *const *volatile *(*const *const volatile *(*)[20U][30U])(void));
#line 284 "input/legacy_function.c"
void a103(int *const *volatile *(*const *const volatile *(*arg)[20U][30U])(void));
#line 291 "input/legacy_function.c"
void cif_a104(int *const *volatile *(*const *const volatile *(*arg)[20U][30U])(void))
{
}
#line 296 "input/legacy_function.c"
void cif_a104(int *const *volatile *(*const *const volatile *(*)[20U][30U])(void));
#line 291 "input/legacy_function.c"
void a104(int *const *volatile *(*const *const volatile *(*arg)[20U][30U])(void));
#line 299 "input/legacy_function.c"
void (*cif_a110(void))(void)
{
  return ( ( void (*)(void)) 0 );
}
#line 304 "input/legacy_function.c"
void (*cif_a110(void))(void);
#line 299 "input/legacy_function.c"
void (*a110(void))(void);
#line 307 "input/legacy_function.c"
void cif_a111(int (*(*arg)(void))(void))
{
}
#line 311 "input/legacy_function.c"
void cif_a111(int (*(*)(void))(void));
#line 307 "input/legacy_function.c"
void a111(int (*(*arg)(void))(void));
#line 314 "input/legacy_function.c"
void cif_a112(int (*(*arg)(void))(void))
{
}
#line 318 "input/legacy_function.c"
void cif_a112(int (*(*)(void))(void));
#line 314 "input/legacy_function.c"
void a112(int (*(*arg)(void))(void));
#line 321 "input/legacy_function.c"
void cif_a113(int (*const *(*arg)(void))(void))
{
}
#line 325 "input/legacy_function.c"
void cif_a113(int (*const *(*)(void))(void));
#line 321 "input/legacy_function.c"
void a113(int (*const *(*arg)(void))(void));
#line 328 "input/legacy_function.c"
void cif_a114(int (*const *(*arg)(void))(void))
{
}
#line 333 "input/legacy_function.c"
void cif_a114(int (*const *(*)(void))(void));
#line 328 "input/legacy_function.c"
void a114(int (*const *(*arg)(void))(void));
#line 336 "input/legacy_function.c"
void **(*cif_a120(void))(void)
{
  return ( ( void **(*)(void)) 0 );
}
#line 341 "input/legacy_function.c"
void **(*cif_a120(void))(void);
#line 336 "input/legacy_function.c"
void **(*a120(void))(void);
#line 344 "input/legacy_function.c"
void cif_a121(int **(*(*arg)(void))(void))
{
}
#line 348 "input/legacy_function.c"
void cif_a121(int **(*(*)(void))(void));
#line 344 "input/legacy_function.c"
void a121(int **(*(*arg)(void))(void));
#line 351 "input/legacy_function.c"
void cif_a122(int **(*(*arg)(void))(void))
{
}
#line 355 "input/legacy_function.c"
void cif_a122(int **(*(*)(void))(void));
#line 351 "input/legacy_function.c"
void a122(int **(*(*arg)(void))(void));
#line 358 "input/legacy_function.c"
void cif_a123(int *const volatile *(*const *(*arg)(void))(void))
{
}
#line 362 "input/legacy_function.c"
void cif_a123(int *const volatile *(*const *(*)(void))(void));
#line 358 "input/legacy_function.c"
void a123(int *const volatile *(*const *(*arg)(void))(void));
#line 365 "input/legacy_function.c"
void cif_a124(int *const volatile *(*const *(*arg)(void))(void))
{
}
#line 370 "input/legacy_function.c"
void cif_a124(int *const volatile *(*const *(*)(void))(void));
#line 365 "input/legacy_function.c"
void a124(int *const volatile *(*const *(*arg)(void))(void));
#line 373 "input/legacy_function.c"
void cif_a131(int arg1, double arg2)
{
}
#line 377 "input/legacy_function.c"
void cif_a131(int, double);
#line 373 "input/legacy_function.c"
void a131(int arg1, double arg2);
#line 380 "input/legacy_function.c"
void cif_a132(int arg1, double arg2)
{
}
#line 384 "input/legacy_function.c"
void cif_a132(int, double);
#line 380 "input/legacy_function.c"
void a132(int arg1, double arg2);
#line 387 "input/legacy_function.c"
void cif_a133(int *const *volatile *(*const *volatile *arg1)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*arg2)[20U][30U])(void))
{
}
#line 391 "input/legacy_function.c"
void cif_a133(int *const *volatile *(*const *volatile *)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*)[20U][30U])(void));
#line 387 "input/legacy_function.c"
void a133(int *const *volatile *(*const *volatile *arg1)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*arg2)[20U][30U])(void));
#line 394 "input/legacy_function.c"
void cif_a134(int *const *volatile *(*const *volatile *arg1)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*arg2)[20U][30U])(void))
{
}
#line 399 "input/legacy_function.c"
void cif_a134(int *const *volatile *(*const *volatile *)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*)[20U][30U])(void));
#line 394 "input/legacy_function.c"
void a134(int *const *volatile *(*const *volatile *arg1)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*arg2)[20U][30U])(void));
#line 402 "input/legacy_function.c"
inline void cif_a141(int arg1, double arg2)
{
}
#line 407 "input/legacy_function.c"
inline void cif_a141(int, double);
#line 402 "input/legacy_function.c"
inline void a141(int arg1, double arg2);
#line 410 "input/legacy_function.c"
static void cif_a151(int arg1, double arg2)
{
}
#line 415 "input/legacy_function.c"
static void cif_a151(int, double);
#line 410 "input/legacy_function.c"
static void a151(int arg1, double arg2);
#line 418 "input/legacy_function.c"
static inline void cif_a161(int arg1, double arg2)
{
}
#line 1 "work/legacy_function.c.aux"
void a011(int arg)
{
#line 5 "work/legacy_function.c.aux"
  cif_a011 ( arg );
}
void a012(int arg)
{
#line 11 "work/legacy_function.c.aux"
  cif_a012 ( arg );
}
void a013(long long unsigned int const arg)
{
#line 17 "work/legacy_function.c.aux"
  cif_a013 ( arg );
}
void a014(long double arg)
{
#line 23 "work/legacy_function.c.aux"
  cif_a014 ( arg );
}
void *a020(int *arg)
{
#line 29 "work/legacy_function.c.aux"
  cif_a020 ( arg );
}
void a021(int *arg)
{
#line 35 "work/legacy_function.c.aux"
  cif_a021 ( arg );
}
void a022(int *arg)
{
#line 41 "work/legacy_function.c.aux"
  cif_a022 ( arg );
}
void a023(int *const *volatile arg)
{
#line 47 "work/legacy_function.c.aux"
  cif_a023 ( arg );
}
void a024(int *const *volatile arg)
{
#line 53 "work/legacy_function.c.aux"
  cif_a024 ( arg );
}
void a031(int *arg)
{
#line 59 "work/legacy_function.c.aux"
  cif_a031 ( arg );
}
void a032(int *arg)
{
#line 65 "work/legacy_function.c.aux"
  cif_a032 ( arg );
}
void a033(int (*arg)[20U][30U])
{
#line 71 "work/legacy_function.c.aux"
  cif_a033 ( arg );
}
void a034(int (*arg)[20U][30U])
{
#line 77 "work/legacy_function.c.aux"
  cif_a034 ( arg );
}
void a041(int **arg)
{
#line 83 "work/legacy_function.c.aux"
  cif_a041 ( arg );
}
void a042(int **arg)
{
#line 89 "work/legacy_function.c.aux"
  cif_a042 ( arg );
}
void a043(int *const *volatile (*arg)[20U][30U])
{
#line 95 "work/legacy_function.c.aux"
  cif_a043 ( arg );
}
void a044(int *const *volatile (*arg)[20U][30U])
{
#line 101 "work/legacy_function.c.aux"
  cif_a044 ( arg );
}
void a051(int (*arg)[10U])
{
#line 107 "work/legacy_function.c.aux"
  cif_a051 ( arg );
}
void a052(int (*arg)[10U])
{
#line 113 "work/legacy_function.c.aux"
  cif_a052 ( arg );
}
void a053(int (*const *volatile arg)[10U][20U][30U])
{
#line 119 "work/legacy_function.c.aux"
  cif_a053 ( arg );
}
void a054(int (*const *volatile arg)[10U][20U][30U])
{
#line 125 "work/legacy_function.c.aux"
  cif_a054 ( arg );
}
void a061(int **(*arg)[10U])
{
#line 131 "work/legacy_function.c.aux"
  cif_a061 ( arg );
}
void a062(int **(*arg)[10U])
{
#line 137 "work/legacy_function.c.aux"
  cif_a062 ( arg );
}
void a063(int *const *volatile (*const *volatile arg)[10U][20U][30U])
{
#line 143 "work/legacy_function.c.aux"
  cif_a063 ( arg );
}
void a064(int *const *volatile (*const *volatile arg)[10U][20U][30U])
{
#line 149 "work/legacy_function.c.aux"
  cif_a064 ( arg );
}
void a071(int (*arg)(void))
{
#line 155 "work/legacy_function.c.aux"
  cif_a071 ( arg );
}
void a072(int (*arg)(void))
{
#line 161 "work/legacy_function.c.aux"
  cif_a072 ( arg );
}
void a073(int (*const arg)(void))
{
#line 167 "work/legacy_function.c.aux"
  cif_a073 ( arg );
}
void a074(int (*const arg)(void))
{
#line 173 "work/legacy_function.c.aux"
  cif_a074 ( arg );
}
void a081(int **(*arg)(void))
{
#line 179 "work/legacy_function.c.aux"
  cif_a081 ( arg );
}
void a082(int **(*arg)(void))
{
#line 185 "work/legacy_function.c.aux"
  cif_a082 ( arg );
}
void a083(int *const *volatile *(*const arg)(void))
{
#line 191 "work/legacy_function.c.aux"
  cif_a083 ( arg );
}
void a084(int *const *volatile *(*const arg)(void))
{
#line 197 "work/legacy_function.c.aux"
  cif_a084 ( arg );
}
void a091(int (**arg)(void))
{
#line 203 "work/legacy_function.c.aux"
  cif_a091 ( arg );
}
void a092(int (**arg)(void))
{
#line 209 "work/legacy_function.c.aux"
  cif_a092 ( arg );
}
void a093(int (*const (*arg)[20U][30U])(void))
{
#line 215 "work/legacy_function.c.aux"
  cif_a093 ( arg );
}
void a094(int (*const (*arg)[20U][30U])(void))
{
#line 221 "work/legacy_function.c.aux"
  cif_a094 ( arg );
}
void a101(int **(**arg)(void))
{
#line 227 "work/legacy_function.c.aux"
  cif_a101 ( arg );
}
void a102(int **(**arg)(void))
{
#line 233 "work/legacy_function.c.aux"
  cif_a102 ( arg );
}
void a103(int *const *volatile *(*const *const volatile *(*arg)[20U][30U])(void))
{
#line 239 "work/legacy_function.c.aux"
  cif_a103 ( arg );
}
void a104(int *const *volatile *(*const *const volatile *(*arg)[20U][30U])(void))
{
#line 245 "work/legacy_function.c.aux"
  cif_a104 ( arg );
}
void (*a110(void))(void)
{
#line 251 "work/legacy_function.c.aux"
  cif_a110 ( );
}
void a111(int (*(*arg)(void))(void))
{
#line 257 "work/legacy_function.c.aux"
  cif_a111 ( arg );
}
void a112(int (*(*arg)(void))(void))
{
#line 263 "work/legacy_function.c.aux"
  cif_a112 ( arg );
}
void a113(int (*const *(*arg)(void))(void))
{
#line 269 "work/legacy_function.c.aux"
  cif_a113 ( arg );
}
void a114(int (*const *(*arg)(void))(void))
{
#line 275 "work/legacy_function.c.aux"
  cif_a114 ( arg );
}
void **(*a120(void))(void)
{
#line 281 "work/legacy_function.c.aux"
  cif_a120 ( );
}
void a121(int **(*(*arg)(void))(void))
{
#line 287 "work/legacy_function.c.aux"
  cif_a121 ( arg );
}
void a122(int **(*(*arg)(void))(void))
{
#line 293 "work/legacy_function.c.aux"
  cif_a122 ( arg );
}
void a123(int *const volatile *(*const *(*arg)(void))(void))
{
#line 299 "work/legacy_function.c.aux"
  cif_a123 ( arg );
}
void a124(int *const volatile *(*const *(*arg)(void))(void))
{
#line 305 "work/legacy_function.c.aux"
  cif_a124 ( arg );
}
void a131(int arg1, double arg2)
{
#line 311 "work/legacy_function.c.aux"
  cif_a131 ( arg1 , arg2 );
}
void a132(int arg1, double arg2)
{
#line 317 "work/legacy_function.c.aux"
  cif_a132 ( arg1 , arg2 );
}
void a133(int *const *volatile *(*const *volatile *arg1)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*arg2)[20U][30U])(void))
{
#line 323 "work/legacy_function.c.aux"
  cif_a133 ( arg1 , arg2 );
}
void a134(int *const *volatile *(*const *volatile *arg1)[10U][20U][30U], int *const *volatile *(*const *const volatile *(*arg2)[20U][30U])(void))
{
#line 329 "work/legacy_function.c.aux"
  cif_a134 ( arg1 , arg2 );
}
inline void a141(int arg1, double arg2)
{
#line 335 "work/legacy_function.c.aux"
  cif_a141 ( arg1 , arg2 );
}
static void a151(int arg1, double arg2)
{
#line 341 "work/legacy_function.c.aux"
  cif_a151 ( arg1 , arg2 );
}
static inline void a161(int arg1, double arg2)
{
#line 347 "work/legacy_function.c.aux"
  int cif_a161();
#line 347 "work/legacy_function.c.aux"
  cif_a161 ( arg1 , arg2 );
}
