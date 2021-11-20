#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	char	*string_w_shit = "   xxxxtripouille";
	char	*shit = " x";
	char	*trimmed_str;
	
	trimmed_str = ft_strtrim(string_w_shit, shit);
	printf("result: %s\n", trimmed_str);
	free(trimmed_str);
	return (0);
}
