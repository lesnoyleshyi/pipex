#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len);

int	main(void)
{
	char	str1[15] = "This is string";
	char	str2[15] = "This is string";

	printf("Before memmove:\t\t%s\n\n", str1);	
	memmove(str1 + 4, str1, 8);
	printf("After memmove:\t\t%s\n", str1);
	ft_memmove(str2 + 4, str2, 8);
	printf("After ft_memmove:\t%s\n", str2);

	return (0);
}
