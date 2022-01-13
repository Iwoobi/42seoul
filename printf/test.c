#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int main()
{
    int a = printf("%0.5d\n",-12);
    printf("%d",a);
}