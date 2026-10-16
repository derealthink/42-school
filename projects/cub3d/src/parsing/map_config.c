/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:28:55 by aielo             #+#    #+#             */
/*   Updated: 2026/01/29 17:29:29 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_line_count(t_ulines *head)
{
	t_ulines	*current;
	int			count;

	current = head;
	count = 0;
	while (current)
	{
		if (current->type == MAP_LINE)
			count++;
		current = current->next;
	}
	return (count);
}

char	*fill_line(char *line, int max)
{
	char	*res;
	int		len;
	int		i;

	if (!line || max <= 0)
		return (NULL);
	len = ft_strlen(line);
	res = malloc(sizeof(char) * (max + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, line, len);
	i = len;
	while (i < max)
		res[i++] = ' ';
	res[i] = '\0';
	return (res);
}

int	fill_map_array(char **arr, t_ulines *head, int len)
{
	t_ulines	*current;
	int			i;

	current = head;
	i = 0;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			arr[i] = fill_line(current->line, current->max);
			if (!arr[i])
			{
				free_map(arr);
				return (0);
			}
			i++;
		}
		current = current->next;
	}
	arr[len] = NULL;
	return (1);
}

char	**map_config(t_data *game, t_ulines *head)
{
	int		len;
	char	**arr;

	(void)game;
	len = map_line_count(head);
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	if (!fill_map_array(arr, head, len))
		return (NULL);
	return (arr);
}
