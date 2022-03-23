#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	return (strlen);
}

int main()
{
	char *a;

	printf("%d",ft_strlen(a));
    
}
