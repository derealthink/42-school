#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	strlen(const char *str);

int  open_file(void)
{
    static int	fd;

	fd = open("lorem.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("error");
		return (1);
	}
	return (fd);
}

char	*fill_str(const char *src, size_t len)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while(i < len)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

#define BUF_SIZE 10

char	*read_buf(int fd)
{
	char	buffer[BUF_SIZE + 1];
	ssize_t	bytes_read;
	char	*result;
	char	*temp;
	char	*joined;

	result = NULL;
	while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		temp = fill_str(buffer, bytes_read);
		if (!temp)
			return (NULL);
		if (!result)
			result = temp;
		else
		{
			joined = strjoin(result, temp);
			free(result);
			free(temp);
			result = joined;
		}
		if (strchr(buffer, '\n'))
			break;
	}
	return (result);
}
char	*strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	t_len;
	size_t	i;
	size_t	j;

	t_len = (strlen(s1)) + (strlen(s2));
	str = (char *)malloc(t_len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
size_t	strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int main(void)
{
    int     fd;
    char    *line;

    fd = open_file();
    if (fd == -1)
        return (1);

    line = read_buf(fd);
    if (line)
    {
        printf("Read line: %s\n", line);
        free(line);
    }
    else
        printf("Nothing read or error occurred.\n");

    close(fd);
    return (0);
}