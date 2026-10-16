#include "pipex.h"

void	child_proc(char **argv, char **envp, int *fd)
{
	int	read_end;

	read_end = open(argv[1], O_RDONLY, 0777);
	if (read_end == -1)
		exit (1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(read_end, STDIN_FILENO);
	close(fd[0]);
	close(read_end);
	exec(argv[2], envp);
}

void	parent_proc(char **argv, char **envp, int *fd)
{
	int	write_end;

	write_end = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (write_end == -1)
		exit(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(write_end, STDOUT_FILENO);
	close(fd[1]);
	close(write_end);
	exec(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			exit (1);
		pid = fork();
		if (pid == -1)
			exit (1);
		else if (pid == 0)
			child_proc(argv, envp, fd);
		waitpid(pid, NULL, 0);
		close(fd[1]);
		parent_proc(argv, envp, fd);
	}
	else 
	{
		printf("error");
	}
	return (0);
}
