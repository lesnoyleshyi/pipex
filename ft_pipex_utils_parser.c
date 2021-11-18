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
	if (!cmd_name)
		return (NULL);
	directories = ft_get_directories(envp);
	if (!directories)
		return (NULL);
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
	free(directories);
	free(cmd_name);
	return (NULL);
}
