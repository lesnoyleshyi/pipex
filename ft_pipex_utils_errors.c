/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:07:01 by stycho            #+#    #+#             */
/*   Updated: 2021/11/20 15:07:03 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror_and_exit(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	ft_pmessage_and_exit(const char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_pcmd_error_and_exit(char	*cmd_w_flags)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	write(2, cmd_w_flags, ft_strlen_sp(cmd_w_flags));
	write(2, "\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_strlen_sp(const char *cmd_w_flags)
{
	int	i;

	i = 0;
	while (cmd_w_flags[i] && cmd_w_flags[i] != ' ')
		i++;
	return (i);
}
