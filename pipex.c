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
	pid_t	cp_switch;
	int		fds[2];

	if (argc != 5)
		ft_pmessage_and_exit("Wrong arguments count\n");
	pipe(fds);
	cp_switch = fork();
	if (cp_switch == -1)
		ft_perror_and_exit("Unable to fork");
	if (cp_switch == 0)
	{
		close(fds[0]);
		fd_src_file = open(argv[1], O_RDONLY);
		dup2(fd_src_file, 0);
		dup2(fds[1], 1);
		execve("path_to_cmd1", "array_of_parameters", envp);
		return (0);
//		make_child_program;
//		дочерний процесс читает из файла1,
//		исполняет программу команда1 и
//		пишет вывод команды1 в трубу
	}
	else
	{
		if (wait() == -1)
			ft_perror_and_exit("Error in child process");
		close(fds[1]);
		fd_dst_file = open(argv[4], O_WRONLY | O_CREAT, 0644);
		dup2(fds[0], 0);
		dup2(fd_dst_file, 1);
		execve("path_to_cmd2", "array_of_parameters", enpv);
//		make_parent_program;
//		родительский процесс читает из трубы,
//		выполняет программу команда2 и
//		пишет вывод команды2 в файл2
	}
	return (0);
}
