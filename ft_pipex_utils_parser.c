/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:52:26 by stycho            #+#    #+#             */
/*   Updated: 2021/11/18 23:52:27 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *cmd_w_flags, char *envp[])
{
	char	**directories;
	char	*cmd_name;
	char	*path;
	int		i;

	cmd_name = ft_get_cmd_name(cmd_w_flags);
	directories = ft_get_directories(envp);
	ft_check_params(cmd_name, directories);
	i = 0;
	while (directories[i])
	{
		path = ft_strjoin(directories[i++], cmd_name);
		if (access(path, X_OK) == 0)
		{
			free(cmd_name);
			ft_free_array(directories);
			return (path);
		}
		free(path);
	}
	ft_free_array(directories);
	free(cmd_name);
	return (NULL);
}

char	*ft_get_cmd_name(const char *cmd_name_with_flags)
{
	char	*cmd_name;
	int		i;
	int		j;

	j = 0;
	while (cmd_name_with_flags[j] && cmd_name_with_flags[j] == ' ')
		j++;
	i = 0;
	while (cmd_name_with_flags[j + i] && cmd_name_with_flags[j + i] != ' ')
		i++;
	if (i == 0)
		return (NULL);
	cmd_name = (char *)malloc(sizeof(char) * (i + 2));
	if (!cmd_name)
		return (NULL);
	cmd_name[i + 1] = '\0';
	while (i != 0)
	{
		cmd_name[i] = cmd_name_with_flags[j + i - 1];
		i--;
	}
	cmd_name[i] = '/';
	return (cmd_name);
}

char	**ft_get_params(char *cmd_name_with_flags)
{
	char	**params;

	params = ft_split(cmd_name_with_flags, ' ');
	return (params);
}

void	ft_check_params(char *path_to_cmd, char *params_for_execve[])
{
	if (!path_to_cmd)
		ft_pmessage_and_exit("command not found\n");
	if (!params_for_execve)
	{
		if (path_to_cmd)
			free(path_to_cmd);
		ft_pmessage_and_exit("error passing args to cmd or receiving dirs");
	}
}

char	**ft_get_directories(char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
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
