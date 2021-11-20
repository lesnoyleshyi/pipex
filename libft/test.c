#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c);

int	main(void)
{
	int	c;
	int res1;
	int res2;

	c = 126;
	res1 = isprint(c);
	printf("Result of isprint: %d\n", res1);
	res2 = ft_isprint(c);
	printf("Result of ft_isprint: %d\n", res2);

	return (0);
}
