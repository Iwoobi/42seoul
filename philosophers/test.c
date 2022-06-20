#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*fx(void *a)
{
	printf("hello\n");
	exit(-1);
}

int main()
{
	pthread_t a;
	
	pthread_create(&a,NULL, (void *)fx, (void *)1);
	printf("aaaa\n\n\n");
	while(1)
	{
		usleep(1000);
		printf("aaaa\n\n\n");
	}
}