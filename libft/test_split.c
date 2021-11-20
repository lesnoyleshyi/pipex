#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
//	char	*raw_str = " Tripouille ";
    char	*raw_str = "--1gfhgdgh-2rger--3geg---4gerg----5egr-----42";
	char	delimiter;
	char	**list_of_strings;
	size_t	i;

//	delimiter = ' ';
    delimiter = '-';
    printf("Does it work?\n");
	list_of_strings = ft_split(raw_str, delimiter);
	printf("exit from func successfully\n");
	if (!(list_of_strings))
	{
		printf("Wake up, Neo. Bad news for you\n");
		return (1);
	}
	i = 1;
	while (list_of_strings[i - 1])
	{
		printf("String №%lu:\t%s\n", i, list_of_strings[i - 1]);
		i++;
		free(list_of_strings[i - 1]);
	}
//	if (list_of_strings[1] == NULL)
//	    printf("Second argument is NULL\n");
	if (strcmp(list_of_strings[1], "42") == 0)
		printf("Test4 OK!\n");
	free(list_of_strings);
	return (0);
}
