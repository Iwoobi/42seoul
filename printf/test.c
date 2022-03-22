#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
int test(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    write(1, va_arg(ap, int *), 1);
}
va_arg(a, char *)
|97||
int main()
{
    test("a",'a');
}