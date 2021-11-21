#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	printf("%s\n", argv[0]);
	printf("Program is running and got string: ");
	while (argv[++i] != NULL)
		printf("%s ", argv[i]);
	printf("\n");
	return (0);
}
