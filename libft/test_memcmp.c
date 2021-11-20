#define C 20
#include <stdio.h>
#include <string.h>

char	ft_memcmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	int my_delta;
	int orig_delta;

	char *str1 = "ThIs iS tHe fIrSt StRiNg FOR y ";
	char *str2 = "ThIs iS tHe fIrSt StRiNg FOR you";

	my_delta = ft_memcmp(str1, str2, C);
	orig_delta = memcmp(str1, str2, C);
	
	printf("ft_memcmp:\t%d\nmemcmp:\t\t%d\n", my_delta, orig_delta);
	return(0);
}
