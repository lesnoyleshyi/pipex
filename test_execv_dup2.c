#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[])
{
	int		fd_of_file;

	fd_of_file = open("file3.txt", O_RDONLY);
	dup2(fd_of_file, 0);
	execv("/usr/bin/wc", argv);
	return (0);
}
