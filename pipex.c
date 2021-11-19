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

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	cp_switch;
	int		fds[2];
	int		status;

	if (argc != 5)
		ft_pmessage_and_exit("Wrong arguments count\n");
	if (pipe(fds) == -1)
		ft_perror_and_exit("Can't create pipe");
	cp_switch = fork();
	if (cp_switch == -1)
		ft_perror_and_exit("Unable to fork");
	if (cp_switch == 0)
		ft_write_to_pipe_from_infile(fds, argv, envp);
	else
	{
		if (wait(&status) == -1)
			ft_perror_and_exit("Error closing child process");
		if (!WIFEXITED(status))
			ft_perror_and_exit("Error in child process");
		ft_read_from_pipe_to_outfile(fds, argv, envp);
	}
	if (close(fds[1]) == -1 | close(fds[0]) == -1)
		ft_perror_and_exit("Can't close one of pipes filedes");
	return (0);
}

void	ft_write_to_pipe_from_infile(int *fds, char *argv[], char *envp[])
{
	int		src_file_fd;
	char	*path_to_cmd1;
	char	**params_for_execve;

	if (close(fds[0]) == -1)
		ft_perror_and_exit("Can't close pipes output");
	src_file_fd = open(argv[1], O_RDONLY);
	if (src_file_fd == -1)
		ft_perror_and_exit("Can't open input file");
	if (dup2(src_file_fd, 0) == -1 | dup2(fds[1], 1) == -1)
		ft_perror_and_exit("Can't turn STDIN to infile or STDOUT to pipes inp");
	path_to_cmd1 = ft_get_path(argv[2], envp);
	params_for_execve = ft_get_params(argv[2]);
	if (execve(path_to_cmd1, params_for_execve, envp) == -1)
	{
		free(path_to_cmd1);
		ft_free_array(params_for_execve);
		ft_perror_and_exit("Error executing cmd1");
	}
	free(path_to_cmd1);
	ft_free_array(params_for_execve);
	if (close(src_file_fd) == -1)
		ft_perror_and_exit("Can't close source files");
	exit(EXIT_SUCCESS);
}

void	ft_read_from_pipe_to_outfile(int *fds, char *argv[], char *envp[])
{
	int		dst_file_fd;
	char	*path_to_cmd2;
	char	**params_for_execve;

	if (close(fds[1]) == -1)
		ft_perror_and_exit("Can't close pipes input");
	dst_file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dst_file_fd == -1)
		ft_perror_and_exit("Can't open or create output file");
	if (dup2(fds[0], 0) == -1)
		ft_perror_and_exit("Can't turn STDIN to pipes output");
	if (dup2(dst_file_fd, 1) == -1)
		ft_perror_and_exit("Can't turn STDOUT to output file");
	path_to_cmd2 = ft_get_path(argv[3], envp);
	params_for_execve = ft_get_params(argv[3]);
	if (execve(path_to_cmd2, params_for_execve, envp) == -1)
	{
		free(path_to_cmd2);
		ft_free_array(params_for_execve);
		ft_perror_and_exit("Error executing cmd2");
	}
	free(path_to_cmd2);
	ft_free_array(params_for_execve);
}
