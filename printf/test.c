#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
int test(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    printf("%d\n", va_arg(ap,int));
    printf("%d", va_arg(ap,int));
    return (0);
}

int main()
{
    test("b",'a',"a");
    printf("%c","a");
}
