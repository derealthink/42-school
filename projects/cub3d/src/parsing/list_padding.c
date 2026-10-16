/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:51:03 by uponci            #+#    #+#             */
/*   Updated: 2026/03/02 10:51:06 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	rm_nl(t_ulines *head)
{
	t_ulines	*current;
	size_t		len;

	current = head;
	while (current)
	{
		if (current->line && current->type == MAP_LINE)
		{
			len = ft_strlen(current->line);
			if (len > 0 && current->line[len - 1] == '\n')
				current->line[len - 1] = '\0';
		}
		current = current->next;
	}
}

void	max_len(t_ulines *head)
{
	t_ulines	*current;
	int			len;
	int			max;

	current = head;
	max = 0;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			len = ft_strlen(current->line);
			if (len > max)
				max = len;
		}
		current = current->next;
	}
	current = head;
	while (current)
	{
		current->max = max;
		current = current->next;
	}
}

void	pad_insert(t_ulines *head, int max)
{
	t_ulines	*current;
	int			len;
	int			res;

	current = head;
	while (current)
	{
		if (current->type == MAP_LINE)
		{
			len = ft_strlen(current->line);
			res = max - len;
			if (res)
				current->pad = res;
		}
		current = current->next;
	}
}

void	prep_pad(t_ulines *head)
{
	rm_nl(head);
	max_len(head);
	pad_insert(head, head->max);
}
