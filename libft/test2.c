#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

int	main(void)
{
	char *s;
	int res1;
	int res2;

	s = "test string with len=23";
	res1 = strlen(s);
	printf("Result of strlen: %d\n", res1);
	res2 = ft_strlen(s);
	printf("Result of ft_strlen: %d\n", res2);

	return (0);
}
