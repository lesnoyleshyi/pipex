#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*path;

	if (argc != 2)
	{
		ft_putstr_fd("Pass only one arg in quotes\n", 1);
		return (1);
	}
	path = ft_get_path(argv[1], envp);
	if (!path)
	{
		ft_putstr_fd("ft_gwt_path returned NULL\n", 1);
		return (1);
	}
	ft_putstr_fd(path, 1);
	free (path);
//	while (1)
//	{
//		check_leaks;
//		;
//	}
	return (0);
}