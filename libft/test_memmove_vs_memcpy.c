# include <string.h>

int	main(void)
{
	char str1[40] = "This string is for test purposes";
	char str2[40] = "This too";
	char *p1;
	char *p2;

	p1 = str1;
	p2 = str1;

	printf("Str1 before execution:\t%s", str1);
	memcpy(str1 + 5,str1 , 4);
	printf("Str1 after memcpy:\t%s", str1);
	return (0);
}
