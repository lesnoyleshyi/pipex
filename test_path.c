#include <stdio.h>
#include "pipex.h"
#include "libft/libft.h"

char	**ft_get_paths(char *envp[]);

int main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	int		i;

	argc = 0;
	argv = NULL;
	paths = ft_get_paths(envp);
	if (!paths)
		printf("ft_get_paths returned NULL");
	i = 0;
	while (paths[i])
	{
		printf("%d: %s\n", i, paths[i]);
		free(paths[i]);
		i++;
	}
	free(paths);
	return (0);
}

char	**ft_get_paths(char *envp[])
{
	int 	i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 1000))
		{
			paths = ft_split((envp[i++]) + 5, ':');
			break ;
		}
		else
			i++;
	}
	return (paths);
}
