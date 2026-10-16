#ifndef	PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


char	**ft_split(char *str, char del);
char	*ft_strjoin(char *s1, char *s2);
void	exec(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	error(void);





#endif