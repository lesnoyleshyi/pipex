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
