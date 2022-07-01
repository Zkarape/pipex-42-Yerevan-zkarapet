/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:10:59 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/01 19:18:08 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parsing(char **env, char *cmd_arg)
{
	char	**splitted;
	int		i;
	char	*join1;
	char	*join2;
	char	**cmd;

	i = 0;
	splitted = NULL;
	cmd = ft_split(cmd_arg, ' ');
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			splitted = ft_split(*env + 5, ':');
			break ;
		}
		env++;
	}
	while (splitted[i])
	{
		join1 = ft_strjoin(splitted[i], "/");
		join2 = ft_strjoin(join1, cmd[0]);
		if (access(join2, F_OK) == 0)
			break ;
		free(join1);
		free(join2);
		i++;
	}
	double_free(splitted);
	return (join2);
}
