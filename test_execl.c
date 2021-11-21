#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	argc = 0;
	printf("The program with this name will be executed: %s\n\n", argv[0]);
	printf("The program is running: %s\n", argv[0]);
	execl("test_main", " ", "Hello", "World!", NULL);
	return (0);
}
