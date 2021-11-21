#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
//	int		ret;

	argc = 0;
	printf("The following program will be executed: %s\n\n", argv[0]);
	if (execve("/bin/ls", NULL, envp) == -1)
		printf("error in execve catched!\n");
//	printf("execve returns %d\n", ret);
	return (0);
}
