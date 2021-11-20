#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

int	main(void)
{
	char	str1[10] = "000000000";
	char	str2[11] = "This is ok";
	char	str3[10] = "000000000";

	printf("Before memcpy: %s\n", str1);	
	memcpy(str1, str2, 9);
	printf("After memcpy: %s\n\n", str1);
	ft_memcpy(str3, str2, 9);
	printf("After ft_memcpy: %s\n", str3);

	return (0);
}
