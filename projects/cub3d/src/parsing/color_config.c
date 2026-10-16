/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:50:50 by uponci            #+#    #+#             */
/*   Updated: 2026/03/05 16:46:57 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	cc_config(t_ulines *head, t_config *id)
{
	t_ulines	*current;
	char		**res;

	current = head;
	while (current)
	{
		if (current->type == CC_LINE)
		{
			res = ft_split(current->line, ',');
			if (!res)
				return (0);
			res = clean_colors(res);
			if (!res)
				return (0);
			if (range_val(res) && is_only_dig(res))
			{
				id->cc = res;
				return (1);
			}
			else
				free_split(res);
		}
		current = current->next;
	}
	return (0);
}

int	cf_config(t_ulines *head, t_config *id)
{
	t_ulines	*current;
	char		**res;

	current = head;
	while (current)
	{
		if (current->type == CF_LINE)
		{
			res = ft_split(current->line, ',');
			if (!res)
				return (0);
			res = clean_colors(res);
			if (!res)
				return (0);
			if (range_val(res) && is_only_dig(res))
			{
				id->cf = res;
				return (1);
			}
			else
				free_split(res);
		}
		current = current->next;
	}
	return (0);
}

int	range_val(char **arr)
{
	int	i;
	int	num;
	int	count;

	i = 0;
	num = 0;
	count = 0;
	while (arr[i] != NULL)
	{
		num = ft_atoi(arr[i]);
		if (num >= 0 && num <= 255)
			count++;
		i++;
	}
	return (count == 3);
}

char	**clean_colors(char **arr)
{
	int	i;
	int	read;
	int	write;

	if (!arr || !arr[0])
		return (NULL);
	i = 0;
	while (arr[i])
	{
		read = 0;
		write = 0;
		while (arr[i][read])
		{
			if (ft_isdigit(arr[i][read]))
				arr[i][write++] = arr[i][read];
			read++;
		}
		arr[i][write] = '\0';
		if (write == 0)
			return (NULL);
		i++;
	}
	return (arr);
}

int	is_only_dig(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
