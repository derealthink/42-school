/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:51:42 by uponci            #+#    #+#             */
/*   Updated: 2026/03/02 10:51:43 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	no_config(t_ulines *head, t_config *id)
{
	t_ulines	*current;
	char		**res;
	int			fd;

	current = head;
	while (current)
	{
		if (current->type == NO_LINE)
		{
			res = ft_split(current->line, ' ');
			if (!res || !res[1])
				return (0);
			fd = open(res[1], O_RDONLY);
			if (fd == -1)
			{
				free_split(res);
				return (0);
			}
			close(fd);
			id->no = ft_strdup(res[1]);
			free_split(res);
		}
		current = current->next;
	}
	return (1);
}

int	so_config(t_ulines *head, t_config *id)
{
	t_ulines	*current;
	char		**res;
	int			fd;

	current = head;
	while (current)
	{
		if (current->type == SO_LINE)
		{
			res = ft_split(current->line, ' ');
			if (!res || !res[1])
				return (0);
			fd = open(res[1], O_RDONLY);
			if (fd == -1)
			{
				free_split(res);
				return (0);
			}
			close(fd);
			id->so = ft_strdup(res[1]);
			free_split(res);
		}
		current = current->next;
	}
	return (1);
}

int	we_config(t_ulines *head, t_config *id)
{
	t_ulines	*current;
	char		**res;
	int			fd;

	current = head;
	while (current)
	{
		if (current->type == WE_LINE)
		{
			res = ft_split(current->line, ' ');
			if (!res || !res[1])
				return (0);
			fd = open(res[1], O_RDONLY);
			if (fd == -1)
			{
				free_split(res);
				return (0);
			}
			close(fd);
			id->we = ft_strdup(res[1]);
			free_split(res);
		}
		current = current->next;
	}
	return (1);
}

int	ea_config(t_ulines *head, t_config *id)
{
	t_ulines	*current;
	char		**res;
	int			fd;

	current = head;
	while (current)
	{
		if (current->type == EA_LINE)
		{
			res = ft_split(current->line, ' ');
			if (!res || !res[1])
				return (0);
			fd = open(res[1], O_RDONLY);
			if (fd == -1)
			{
				free_split(res);
				return (0);
			}
			close(fd);
			id->ea = ft_strdup(res[1]);
			free_split(res);
		}
		current = current->next;
	}
	return (1);
}
