/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:18:28 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/27 18:51:51 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/errno.h>

char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strlen(const char *s);
void	double_free(char **arr);
void	child1(int fd1, int infile, char **av, char **env);
void	child2(int fd0, int outfile, char **av, char **env);
char	*parsing(char **env, char *cmd_arg);
void	pipex(int inffd, int outffd, char **av, char **env);

#endif
