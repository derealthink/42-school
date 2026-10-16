/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:02:32 by aielo             #+#    #+#             */
/*   Updated: 2026/03/10 13:03:42 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_val_chars(char c)
{
	return ((c >= '0' && c <= '9') || c == ' ' || c == ',' || c == '\n');
}

int	is_three_values(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (is_space(line[i]))
			i++;
		if (!ft_isdigit(line[i]))
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		count++;
		if (line[i] == ',' || line[i] == ' ')
			i++;
		else if (line[i] != '\0')
			return (0);
	}
	return (count == 3);
}

int	color_check(t_ulines *head)
{
	t_ulines	*current;
	int			i;

	current = head;
	while (current)
	{
		if (current->type == CC_LINE || current->type == CF_LINE)
		{
			i = 1;
			while (current->line[i])
			{
				if (!is_val_chars(current->line[i]))
					return (0);
				i++;
			}
			if (!is_three_values(current->line + 2))
				return (0);
		}
		current = current->next;
	}
	return (1);
}
