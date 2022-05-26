#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main()
{
	char	*argv[3];

	argv[0] = "cat";
	argv[1] = "file1";
	argv[2] = 0;

	execve("/bin/cat", argv, 0);
}