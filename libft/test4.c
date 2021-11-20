#define C 39
#include <stdio.h>
#include <string.h>

char	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	int my_delta;
	int orig_delta;

	char *str1 = "ThIs iS tHe fIrSt StRiNg FOR ";
	char *str2 = "ThIs iS tHe fIrSt StRiNg FOR ";

	my_delta = ft_strncmp(str1, str2, C);
	orig_delta = strncmp(str1, str2, C);
	
	printf("ft_strncmp:\t%d\nstrncmp:\t%d\n", my_delta, orig_delta);
	return(0);
}
