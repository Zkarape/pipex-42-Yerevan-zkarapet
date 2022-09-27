/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:17:45 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/27 20:30:36 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2(int fd0, int outfile, char **av, char **env)
{
	int		fromcmd1;
	char	*cmd2;
	char	**cmd2_args;
	int		to_outfile;

	fromcmd1 = dup2(fd0, STDIN_FILENO);
	close(fd0);
	to_outfile = dup2(outfile, STDOUT_FILENO);
	close(outfile);
	if (fromcmd1 < 0 || to_outfile < 0)
	{
		perror("dup2() from 2 returns -1");
		exit(EXIT_FAILURE);
	}
	cmd2 = parsing(env, av[3]);
	cmd2_args = ft_split(av[3], ' ');
	execve(cmd2, cmd2_args, env);
	double_free(cmd2_args);
	free(cmd2);
	perror("not lol");
	exit(1);
}
