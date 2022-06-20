# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <signal.h>
int main()
{
	pid_t a;
	pid_t b;
	pid_t c;

	a= fork();
	if (a == 0)
	{
		while(1)
		{
			printf("a\n");
			usleep(1000*1000);
		}
	}
	b = fork();
	if (b == 0)
	{
		while(1)
		{
			printf("b\n");
			usleep(1000*1000);
	
		}
	}
	c = fork();
	if (c == 0)
	{
		while(1)
		{
			printf("c\n");
			usleep(1000*1000);
		}
	}
	printf("asd\n");
	usleep(1000*2000);
	printf("kill a\n");
	kill(a,SIGKILL);
	printf("kill b\n");
	kill(b, SIGKILL);
	printf("kill c\n");
	kill(c, SIGKILL);
	while(1)
	{

	}
}