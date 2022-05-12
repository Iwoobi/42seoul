
#include <fcntl.h>
#include <unistd.h>
int main()
{
	char a[100];
	int fd = open("test.fdf", O_RDONLY);
	read(fd, a, 100);
}