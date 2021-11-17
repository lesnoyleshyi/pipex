/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:12:42 by stycho            #+#    #+#             */
/*   Updated: 2021/11/14 17:12:44 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
void	ft_check_rights(char *arg);
void	ft_free_array(char **array);
void	ft_perror_and_exit(const char *message);
void	ft_pmessage_and_exit(const char *message);
int		ft_check_args(int argc, char **argv);
char	**ft_get_paths(char *envp[]);
#endif
