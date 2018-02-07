void a011(int arg)
{
}
void a012(int arg)
{
}
void a013(unsigned const long long int arg)
{
}
void a014(long double arg)
{
}

void * a020(int *arg)
{
  return 0;
}
void a021(int *arg)
{
}
void a022(int *arg)
{
}
void a023(int * const * volatile arg)
{
}
void a024(int * const * volatile arg)
{
}

void a031(int arg[10])
{
}
void a032(int arg[10])
{
}
void a033(int arg[10][20][30])
{
}
void a034(int arg[10][20][30])
{
}

void a041(int *arg[10])
{
}
void a042(int *arg[10])
{
}
void a043(int * const * volatile arg[10][20][30])
{
}
void a044(int * const * volatile arg[10][20][30])
{
}

void a051(int (*arg)[10])
{
}
void a052(int (*arg)[10])
{
}
void a053(int (* const * volatile arg)[10][20][30])
{
}
void a054(int (* const * volatile arg)[10][20][30])
{
}

void a061(int ** (*arg)[10])
{
}
void a062(int ** (*arg)[10])
{
}
void a063(int * const * volatile (* const * volatile arg)[10][20][30])
{
}
void a064(int * const * volatile (* const * volatile arg)[10][20][30])
{
}

void a071(int (*arg)(void))
{
}
void a072(int (*arg)(void))
{
}
void a073(int (*const arg)(void))
{
}
void a074(int (*const arg)(void))
{
}

void a081(int ** (*arg)(void))
{
}
void a082(int ** (*arg)(void))
{
}
void a083(int * const * volatile *(*const arg)(void))
{
}
void a084(int * const * volatile *(*const arg)(void))
{
}

void a091(int (*arg[10])(void))
{
}
void a092(int (*arg[10])(void))
{
}
void a093(int (* const arg[10][20][30])(void))
{
}
void a094(int (* const arg[10][20][30])(void))
{
}

void a101(int ** (*arg[10])(void))
{
}
void a102(int ** (*arg[10])(void))
{
}
void a103(int * const * volatile *( * const * volatile const *arg[10][20][30])(void))
{
}
void a104(int * const * volatile *( * const * volatile const *arg[10][20][30])(void))
{
}

void (*a110(void))(void)
{
  return 0;
}
void a111(int (*arg(void))(void))
{
}
void a112(int (*arg(void))(void))
{
}
void a113(int (* const * arg(void))(void))
{
}
void a114(int (* const * arg(void))(void))
{
}

void ** (*a120(void))(void)
{
  return 0;
}
void a121(int ** (*arg(void))(void))
{
}
void a122(int ** (*arg(void))(void))
{
}
void a123(int * const volatile * (* const * arg(void))(void))
{
}
void a124(int * const volatile * (* const * (*arg)(void))(void))
{
}

void a131(int arg1, double arg2)
{
}
void a132(int arg1, double arg2)
{
}
void a133(int * const * volatile *(* const * volatile *arg1)[10][20][30], int * const * volatile *(* const * volatile const *arg2[10][20][30])(void))
{
}
void a134(int * const * volatile *(* const * volatile *arg1)[10][20][30], int * const * volatile *(* const * volatile const *arg2[10][20][30])(void))
{
}

inline void a141(int arg1, double arg2)
{
}

static void a151(int arg1, double arg2)
{
}

static inline void a161(int arg1, double arg2)
{
}
