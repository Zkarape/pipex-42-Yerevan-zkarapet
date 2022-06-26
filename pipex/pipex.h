#ifndef PIPEX_H
 #define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/errno.h>

typedef struct variables
{
	int 	infile;
	int 	outfile;
	char 	*path;
}var;

char	 **ft_split(char *s, char c);
char 	*ft_strdup(const char *s);
char 	*ft_strjoin(const char *s1, const char *s2);
int 	ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strlen(const char *s);

#endif
