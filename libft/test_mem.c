#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int	main(void)
{
	char str1[] = "This string is for test purposes for memset";
	char str2[] = "This string is for test purposes for ft_memset";

	memset(str1 + 5, '*', 6);
	printf("%s\n", str1);
	ft_memset(str2 + 5, '*', 6);
	printf("%s\n", str2);

	return (0);
}
