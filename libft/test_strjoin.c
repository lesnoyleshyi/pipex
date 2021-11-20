#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

int	main(void)
{
	char	*s1 = "my favorite animal is";
//	char	*s2 = " ";
	char	*s3 = "the nyancat";
	char	*res;
	
	res = ft_strjoin(s1, s3);
	printf("%s\n", res);
	free(res);
	return (0);
}
