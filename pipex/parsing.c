#include "pipex.h"

char	*parsing(char **env, char *cmd, char **av)
{
	char **splitted;
	int i = 0;
	char *join1;
	char *join2;
	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	printf("^^^%s\n", *env);
	if (!ft_strncmp(*env, "PATH=", 5))
			splitted = ft_split((*env + 5), ':');
	while (splitted[i])
	{
		printf("%s\n", splitted[i]);
		i++;
	}
	i = 0;
	while (splitted[i])
	{
		join1 = ft_strjoin(splitted[i], "/");
		join2 = ft_strjoin(join1, cmd);
		if (!access(join2, F_OK))
			break;
		i++;
	}
	return (join2);
}

void	double_free(char **arr)
{
	int i = 0;
	while (arr[i++])
		free(arr[i]);
}

void	child1(int fd2, int infile, char **av, char **env)
{
	int		from_infile;
	from_infile = dup2(infile, STDIN_FILENO);//STDIN_FILENO == 0
	close(infile);
	int		to_out;
	to_out = dup2(fd2, STDOUT_FILENO);//STDOUT_FILENO == 1
	close(fd2);
	if (from_infile < 0 || to_out < 0)
	{
		perror("dup2() returns -1");
		exit(EXIT_FAILURE);
	}
	char	*cmd1;
	cmd1 = parsing(env, av[2], av);
	char	**needed_args;
	needed_args = ft_split(av[2], ' ');
	execve(cmd1, needed_args, env);
}

void	child2(int fd1, int outfile, char **av, char **env)
{
	int		fromcmd1;
	fromcmd1 = dup2(fd1, STDIN_FILENO);
	close(fd1);
	int		to_outfile;
	to_outfile = dup2(outfile, STDOUT_FILENO);
	close(outfile);
	if (fromcmd1 < 0 || to_outfile < 0)
	{
		perror("dup2() returns -1");
		exit(EXIT_FAILURE);
	}
	char	*cmd2;
	cmd2 = parsing(env, av[3], av);
	char	**cmd2_args;
	cmd2_args = ft_split(av[3], ' ');
	execve(cmd2, cmd2_args, env);
}

void	pipex(int inf, int outf, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fds[2];
	int		pipe_res;

	pipe_res = pipe(fds);
	if (pipe_res < 0)
		perror("pipe() returns -1");
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork() is < 0");	
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)//we are in a child process
		child1(fds[0], inf, av, env);
	else if (pid1 != 0)//we are in parent, we do 2nd fork(), because it's safe to have 2 child processes, cause when child1(cmd1) segfaults, cmd2 is gonna work, otherwise it will segfault too.
	{
		pid2 = fork();
		if (pid2 < 0)
		{
			perror("fork() is < 0");	
			exit(EXIT_FAILURE);
		}
		if (pid2 == 0)
			child2(fds[1], outf, av, env);
		close(fds[0]);
		close(fds[1]);
		waitpid(-1, NULL, 0);
	}
}

int main(int ac, char **av, char **env)
{
	int infile;
	infile = open(av[1], O_RDONLY, 04);
	int outfile;
	outfile = open(av[ac - 1], O_RDONLY | O_CREAT | O_TRUNC, 0644);
	//if the file is already created TRUNC deletes containing of the file and writes new one, 6 - read and write, 4 - read
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
	{
		pipex(infile, outfile, av, env);
	}
}
