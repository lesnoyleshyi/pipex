#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c);

int	main(void)
{
	int	i;
	int	j;
	
	char *str1 = "ThIs iS tHe fIrSt StRiNg FOR tolower()1234567890*#$ ";
	char *str2 = "ThIs iS tHe fIrSt StRiNg FOR ft_TOLOWER()1234567890*#$&";
	printf("%s \n", str1);
	printf("%s \n", str2);

	for (i = 0; str1[i] != '\0'; i++)
	{
		putchar(tolower(str1[i]));
	}
	printf("\n");
	for (j = 0; str2[j] != '\0'; j++)
	{
		putchar(ft_tolower(str2[j]));
	}
	return(0);
}
