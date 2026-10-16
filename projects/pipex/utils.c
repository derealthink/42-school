#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
	while (strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i + 5], ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	exec(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	int		exec_result;
	
	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	exec_result = execve(path, cmd, envp);
	if (exec_result == -1)
	{
		free(path);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
}

void	error(void)
{
	printf("error");
}

