#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int main(void)
{
	char	*test_s = "0123456789";
	char	*res;

	res = ft_substr(test_s, 9, 9);
	printf("%s\n", res);
	free(res);
	return (0);
}
