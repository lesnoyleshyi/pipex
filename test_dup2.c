#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	char buf[100] = "0";
	int	fd_f1;
	int fd_f2;

	fd_f1 = open("file2.txt", O_RDWR);
	fd_f2 = open("file3.txt", O_RDWR);
	dup2(fd_f2, fd_f1);
	read(fd_f1, buf, 99);
	printf("res: %s", buf);


	return (0);
}
