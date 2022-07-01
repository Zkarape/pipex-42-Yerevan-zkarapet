/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:17:57 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/01 19:18:00 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	infile;
	int	outfile;

	infile = open(av[1], O_RDONLY);
	outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infile < 0)
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	else if (outfile < 0)
	{
		perror(av[ac - 1]);
		exit(EXIT_SUCCESS);
	}
	if (ac >= 2)
		pipex(infile, outfile, av, env);
}
