#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	f(unsigned int index, char symb);

int	main(void)
{
	char	*str = "override this !";
	char	*mod_str;

	mod_str = ft_strmapi(str, f);
	printf("Result str: %s\n", mod_str);
	free(mod_str);
	return (0);
}

char	f(unsigned int index, char symb)
{
	char	res;

	index = 0;
	symb = '*';
	res = symb;
	return (res);
}
