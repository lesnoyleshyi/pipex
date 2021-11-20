#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char *str_number;

	str_number = ft_itoa(-2147483648);
	printf("Result: %s\n", str_number);
	free(str_number);
	return (0);
}
