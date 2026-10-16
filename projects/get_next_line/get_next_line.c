/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:42:54 by uponci            #+#    #+#             */
/*   Updated: 2025/05/31 13:42:56 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 10000000

char	*read_buf(int fd)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*result;
	char	*temp;
	char	*joined;

	buffer = malloc(BUF_SIZE + 1);
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
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (result);
}

char	*fill_str(const char *src, size_t len)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

char	*sort_str(char *str_buf, char **extra)
{
	size_t	i;
	char	*line;

	if (!str_buf || str_buf[0] == '\0')
	{
		free(str_buf);
		return (NULL);
	}
	i = 0;
	while (str_buf[i] && str_buf[i] != '\n')
		i++;

	if (str_buf[i] == '\n')
	{
		line = fill_str(str_buf, i + 1);
		*extra = substr(str_buf, i + 1, ft_strlen(str_buf) - i - 1);
	}
	else
	{
		line = fill_str(str_buf, i);
		*extra = NULL;
	}
	free(str_buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*res;
	char		*line;
	char		*buf;

	if (fd < 0)
		return (NULL);
	if (!extra)
		extra = fill_str("", 0);
	buf = NULL;
	if (!ft_strchr(extra, '\n'))
		buf = read_buf(fd);
	if (!buf && extra[0] == '\0')
	{
		free(extra);
		extra = NULL;
		return (NULL);
	}
	res = strjoin(extra, buf);
	free(buf);
	line = sort_str(res, &extra);
	return (line);
}
