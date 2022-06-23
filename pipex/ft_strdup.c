#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = ((char *)s1)[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
