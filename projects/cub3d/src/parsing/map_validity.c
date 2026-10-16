/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:51:17 by uponci            #+#    #+#             */
/*   Updated: 2026/03/02 10:51:19 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_first_val(t_ulines *head)
{
	t_ulines	*current;
	int			i;

	current = head;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			i = 0;
			while (is_space(current->line[i]))
				i++;
			if (current->line[i] != '1')
				return (0);
		}
		current = current->next;
	}
	return (1);
}

int	is_last_val(t_ulines *head)
{
	t_ulines	*current;
	int			i;
	int			len;

	current = head;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			len = ft_strlen(current->line);
			i = len - 1;
			while (i > 0 && is_space(current->line[i]))
				i--;
			if (current->line[i] != '1')
				return (0);
		}
		current = current->next;
	}
	return (1);
}

int	is_fline_val(t_ulines *head)
{
	t_ulines	*current;
	int			i;
	int			len;

	current = head;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			i = 0;
			while (current->line[i] && is_space(current->line[i]))
				i++;
			len = ft_strlen(current->line) - 1;
			while (len > i && is_space(current->line[len]))
				len--;
			while (i <= len)
			{
				if (!is_mapc_val(current->line[i]))
					return (0);
				i++;
			}
		}
		current = current->next;
	}
	return (1);
}

static int	is_line_only_one_space(const char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if ((line[i] != '1') && (line[i] != ' ') && (line[i] != '\n') && 
			(line[i] != '\r')) 
			return (0);
		i++;
	}
	return (1);
}

int	is_first_last_mapline_val(t_ulines *head)
{
	t_ulines	*current;
	t_ulines	*first;
	t_ulines	*last;

	current = head;
	first = NULL;
	last = NULL;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			if (!first)
				first = current;
			last = current;
		}
		current = current->next;
	}
	if (!first || !last)
		return (0);
	if (!is_line_only_one_space(first->line))
		return (0);
	if (!is_line_only_one_space(last->line))
		return (0);
	return (1);
}
