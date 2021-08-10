#if defined(__x86_64__) || defined(__aarch64__)
typedef unsigned long size_t;
#else
typedef unsigned int size_t;
#endif
