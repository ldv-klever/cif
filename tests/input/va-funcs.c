#include <stdarg.h>

void func(int, ...);
void gunc(const char *, ...);
void hunc(const char *, va_list);

void iunc(int arg1, const char *arg2, ...)
{
	va_list args;

	func(arg1);
	gunc(arg2);
	va_start(args, arg2);
	hunc(arg2, args);
	va_end(args);
}

void junc(int arg, va_list va)
{
	func(arg, va);
}
