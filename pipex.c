/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:18:14 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/27 20:42:22 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_pid(pid_t pid)
{
	if (pid < 0)
		error("pid is < 0");
}

void	pipe_error(int pip)
{
	if (pip < 0)
		perror("pipe() returns -1");
}

void	pipex(int inffd, int outffd, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fds[2];
	int		status;

	pipe_error(pipe(fds));
	pid1 = fork();
	error_pid(pid1);
	if (pid1 == 0)
	{
		close(fds[0]);
		child1(fds[1], inffd, av, env);
	}
	pid2 = fork();
	error_pid(pid2);
	if (pid2 == 0)
	{
		close(fds[1]);
		child2(fds[0], outffd, av, env);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
