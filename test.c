#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include <fcntl.h>
#include <unistd.h>
void	error_code(void)
{
	write(2, "error_data", 10);
	exit(1);
}
void	open_file(char *file_1, char *file_2, t_list *data)
{
	data->fd.o_fd = open(file_1, O_RDONLY);
	data->fd.w_fd = open(file_2, O_WRONLY);
	if (data->fd.o_fd == -1 || data->fd.w_fd == -1)
		error_code();
}

void	inputdata_check(int argc, char **argv, t_list *data)
{
	if (argc < 6)
		error_code();
	data->pipex_num = argc - 3;
	open_file(argv[2],argv[argc - 1], data);
}

int	main(int argc, char **argv)
{
	t_list	data;
	pid_t	pid = 1;
	pid_t	pid2 = 1;
	int	status;
	int	fd[2];
	int fd1[2];
	char **a;
	char **b;
	// inputdata_check(argc, argv, &data);
	pipe(fd);
	pipe(fd1);
	printf("out : %d %d %d %d",fd[0], fd[1] , fd1[0], fd1[1]);
	pid = fork();
	if (pid != 0)
		pid2 = fork();
	if (pid2 == 0)
	{
		char **c;
		dup2(fd1[0], 0);
		close(fd[1]);
		close(fd1[1]);
		c = (char **)malloc(sizeof(char *) * 3);
		c[0] = "wc";
		c[1] = "-l";
		c[2] = NULL;
		if (execve("/usr/bin/wc",c, NULL) == -1)
			printf("error");
	}
	else if(pid == 0)					// fd[0] = 4 fd[1] = 6                 pipe파일생성 fd[0] = 파일에서 읽는다 fd[1] = 파일에다 쓴다.
	{
		dup2(fd[0], 0);
		close(fd[1]);
		dup2(fd1[1], 1);
		close(fd1[0]);
		b = (char **)malloc(sizeof(char *) * 3);
		b[0] = "wc";
		b[1] = NULL;
		execve("/usr/bin/wc",b, NULL);
	}
	else
	{
		dup2(fd[1], 1);
		close(fd[0]);
		a = (char **)malloc(sizeof(char *) * 3);
		a[0] = "cat";
		a[1] = "file1";
		a[2] = NULL;
		if (execve("/bin/cat",a, NULL) == -1)
			printf("no cat\n");
	}
}

