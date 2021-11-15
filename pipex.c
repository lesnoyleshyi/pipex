/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:09:30 by stycho            #+#    #+#             */
/*   Updated: 2021/11/14 16:09:32 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	char *error_msg;

	ft_check_args(argc, char *argv[]));


}

void	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5)
		ft_pmessage_and_exit("Wrong arguments count\n", 2);
	if (access(argv[1], R_OK) == -1)
		ft_perror_and_exit("Program exit with message");
	i = 2;
	while (i < argc)
		ft_check_rights(argv[i++]);
}

void	ft_check_rights(char *arg, char *envp[])
{
	int		i;
	char	**paths;
	char	*path_to_check;

	path_to_check = ft_strjoin("/bin/", arg);
	if (access(path_to_check, X_OK) == 0)
	{
		free(path_to_check);
		return ;
	}
	paths = ft_get_paths(envp);
	if (!paths)
		ft_pmessage_and_exit("command not found, exit");
	i = 0;
	while (paths[i])
	{
		path_to_check = ft_strjoin(paths[i++], arg);
		if (access(path_to_check, X_OK) == 0)
		{
			free(path_to_check);
			ft_free_array(paths);
			return	;
		}
		free(path_to_check);
	}
	free(paths);
	ft_perror_and_exit("Program exit with message");
}

void	ft_perror_and_exit(const char *message)
{
	perror(message);
	exit(-1);
}

void	ft_pmessage_and_exit(const char *message)
{
	ft_putstr_fd(message, 2);
	exit(-1);
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
	}
	return (paths);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
