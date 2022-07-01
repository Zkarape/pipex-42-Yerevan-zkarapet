/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:10:59 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/01 22:41:51 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*d_path(char **env_vars, char **cmd)
{
	int		i;
	char	*join1;
	char	*join2;

	i = 0;
	while (env_vars[i])
	{
		join1 = ft_strjoin(env_vars[i], "/");
		join2 = ft_strjoin(join1, cmd[0]);
		if (access(join2, F_OK) == 0)
			break ;
		free(join1);
		free(join2);
		i++;
	}
	double_free(env_vars);
	return (join2);
}

char	*parsing(char **env, char *cmd_arg)
{
	char	**splitted;
	int		i;
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
	return (d_path(splitted, cmd));
}
