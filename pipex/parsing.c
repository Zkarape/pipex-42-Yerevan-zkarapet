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

void	child1(int fd1, int infile, char **av, char **env)
{
	int		to_stdin = dup2(infile, STDIN_FILENO);//STDIN_FILENO == 0
	close(infile);
	int		to_out = dup2(fd1, STDOUT_FILENO);//STDOUT_FILENO == 1
	close(fd1);
	if (to_stdin < 0 || to_out < 0)
		perror("dup2() returns -1");//perror prints and exits
	char	*cmd1;
	cmd1 = parsing(env, av[2], av);
	char	**needed_args;
	needed_args = ft_split(av[2], ' ');
	execve(cmd1, needed_args, env);
}

void	child2(int fd2, int outfile, char **av, char **env)
{

}

void	pipex(int fd1, int fd2, char *cmd1, char *cmd2)
{
	int		status;
	pid_t	pid1;
	pid_t	pid2;
	int		fds[2];
	int		pipe;

	pipe = pipe(fds);
	if (pipe < 0)
		perror("pipe() error");
	pid1 = fork();
	if (pid1 < 0)
		perror("fork() error");
	if (pid1 == 0)//we are in child process
	{
		
	}
}

int main(int argc, char **argv, char **env)
{
	int infile;
	infile = open(av[1], O_RDONLY, 04);
	int outfile;
	outfile = open(av[ac - 1], O_RDONLY, O_CREAT, O_TRUNC, 0644);
	//if the file is already created TRUNC deletes containing of the file and wites new one, 6 - read and write, 4 - read
	//read(infile, av[1], );
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
	if (argc >= 2)
	{
		var var_struct;
		var_struct.path = parsing(env, argv[1], argv);
		
	}
}
