/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:52:42 by uponci            #+#    #+#             */
/*   Updated: 2026/03/02 10:52:44 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	player_char(char c)
{
	return (c == 'W' || c == 'E' || c == 'N' || c == 'S');
}

int	validate_player(t_ulines *head)
{
	t_ulines	*current;
	int			i;
	int			res;

	current = head;
	res = 0;
	while (current)
	{
		i = 0;
		if (current->type == MAP_LINE)
		{
			while (current->line[i])
			{
				if (player_char(current->line[i]))
					res++;
				i++;
			}
		}
		current = current->next;
	}
	if (res != 1)
		return (0);
	return (1);
}

int	is_mapc_val(char c)
{
	if (c == '1' || c == '0' 
		|| c == 'N' || c == 'S' || c == 'E' 
		|| c == 'W' || c == ' ')
		return (1);
	return (0);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
