/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:52:28 by uponci            #+#    #+#             */
/*   Updated: 2026/03/02 10:52:29 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

int	get_map_height(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

int	get_map_width(char **map)
{
	int	w;
	int	i;
	int	len;

	w = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > w)
			w = len;
		i++;
	}
	return (w);
}

char	find_player_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return ('N');
			else if (map[i][j] == 'S')
				return ('S');
			else if (map[i][j] == 'E')
				return ('E');
			else if (map[i][j] == 'W')
				return ('W');
			j++;
		}
		i++;
	}
	return ('0');
}

int	final_parser(char *filename, t_data *game)
{
	if (!list_to_struct(filename, game))
		return (0);
	game->map_height = get_map_height(game->map);
	game->map_width = get_map_width(game->map);
	if (!flood_fill(game))
		return (0);
	return (1);
}
