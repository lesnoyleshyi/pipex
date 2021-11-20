#include <strings.h>
#include <stdio.h>

void	*ft_bzero(void *s,  size_t n);

int	main(void)
{
	char str1[] = "This string is for test purposes for bzero";
	char str2[] = "This string is for test purposes for ft_bzero";

	bzero(str1 + 5, 0);
	printf("%s\n", str1);
	ft_bzero(str2 + 5, 0);
	printf("%s\n", str2);

	return (0);
}
