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

int	main(int argc, char *argv[])
{
	char *error_msg;

	if (ft_check_args(argc, char *argv[]))
		return (1);

}

int	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5)
	{
		write(2, "Wrong arguments count\n", 23);
		exit(1);
	}
	if (access(argv[1], R_OK) == -1)
		ft_perror_and_exit("Program exit with message");
	i = 2;
	while (i < argc)
		ft_check_rights(argv[i++]);
	return (0);
}

void	ft_check_rights(char *arg, char *envp[])
{
	int		i;
	char	**paths;
	char	*path_to_check;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strstr(envp[i], "PATH="))
		{
			paths = ft_split(envp[i++], ':');		// +5 to avoid PATH=
			break ;
		}
	}
	if (!paths)
	{
		write(2, "command not found, exit\n", 24);
		exit(1);
	}
	i = 0;
	while (str[i])
	{
		path_to_check = ft_strjoin(str[i++], arg);

		free(path_to_check);
	}
}

void	ft_perror_and_exit(const char *message)
{
	perror(message);
	exit(1);
}