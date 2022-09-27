/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:16:24 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/27 20:30:32 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int fd1, int infile, char **av, char **env)
{
	int		from_infile;
	int		to_out;
	char	**needed_args;
	char	*cmd1;

	from_infile = dup2(infile, STDIN_FILENO);
	close(infile);
	to_out = dup2(fd1, STDOUT_FILENO);
	close(fd1);
	if (from_infile < 0 || to_out < 0)
	{
		perror("dup2() from child 1 returns -1");
		exit(EXIT_FAILURE);
	}
	cmd1 = parsing(env, av[2]);
	needed_args = ft_split(av[2], ' ');
	execve(cmd1, needed_args, env);
	double_free(needed_args);
	free(cmd1);
	perror("lol");
	exit(1);
}
