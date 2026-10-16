#include "pipex.h"

int	ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	int len_1 = ft_strlen(s1);
	int len_2 = ft_strlen(s2);
	int len = len_1 + len_2; 
	char *res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	int i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[i + len_1] = s2[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}