/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:10:35 by zkarapet          #+#    #+#             */
/*   Updated: 2022/07/01 19:19:14 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dst[i] = ((char *)s1)[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		dst[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
