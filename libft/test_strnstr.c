#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int	main(void)
{
	char str1[30] = "aaabcabcd";
	char str2[10] = "cd";

	printf("My:\t%s\n", ft_strnstr(str1, str2, 8));
	printf("Orig:\t%s\n", strnstr(str1, str2, 8));
	return(0);
}
