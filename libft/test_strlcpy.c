#include <string.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int main(void)
{
	char	buf1[20] = "0";
	char	buf2[20] = "0";
	char	str[] = "the cacke is a lie !\0I'm hidden lol\r\n";

	printf("Orig:\t%s\t%lu\n", buf1, strlcpy(buf1, str, 6));
	printf("My:\t%s\t%lu\n", buf2, ft_strlcpy(buf2, str, 6));
	return(0);
}
