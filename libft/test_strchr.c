#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "tripouille";

	printf("Result  ft_: %s\n", ft_strchr(s, 't' + 256));
	printf("Result orig: %s\n", strchr(s, 't' + 256));
	printf("WTF: %c\n", 't' + 256);

	return (0);
}
