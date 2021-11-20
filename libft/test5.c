#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str);

int	main(void)
{
	char *str_num;

	str_num = "     45678921121213456789";

	printf("ft_atoi:\t%d\n", ft_atoi(str_num));
	printf("atoi:\t\t%d\n", atoi(str_num));
	return (0);
}
