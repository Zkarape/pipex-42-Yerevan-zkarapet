/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:18:14 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/01 19:18:17 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int inffd, int outffd, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fds[2];
	int		pipe_res;
	int		status;

	pipe_res = pipe(fds);
	if (pipe_res < 0)
		perror("pipe() returns -1");
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork() is < 0");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		close(fds[0]);
		child1(fds[1], inffd, av, env);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork() is < 0");
		exit(EXIT_FAILURE);
	}
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
