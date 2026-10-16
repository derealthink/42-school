/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:53:44 by uponci            #+#    #+#             */
/*   Updated: 2026/03/02 10:53:46 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && is_space(line[i]))
	{
		i++;
	}
	return (line[i] == '\0');
}

void	free_list(t_ulines *head)
{
	t_ulines	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->line);
		free(tmp);
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	str_has_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}
