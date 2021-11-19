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
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
void	ft_free_array(char **array);
void	ft_perror_and_exit(const char *message);
void	ft_check_rights(char *arg, char *envp[]);
void	ft_pmessage_and_exit(const char *message);
void	ft_check_args(int argc, char *argv[], char *envp[]);
void	ft_write_to_pipe_from_infile(int *fds, char *argv[], char *envp[]);
void	ft_read_from_pipe_to_outfile(int *fds, char *argv[], char *envp[]);
char	**ft_get_directories(char *envp[]);
char	**ft_get_params(char *cmd_name_with_flags);
char	*ft_get_cmd_name(const char *cmd_name_with_flags);
char	*ft_get_path(char *cmd_w_flags, char *envp[]);
#endif
