#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(void)
{

	char *str1 = "ThIs iS tHe fIrSt StRiNg FOR ";

	printf("%s\n", ft_memchr(str1, 'R', 20));
	printf("%s\n", memchr(str1, 'R', 20));

	return(0);
}
