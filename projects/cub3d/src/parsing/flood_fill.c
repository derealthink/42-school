/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:51:54 by uponci            #+#    #+#             */
/*   Updated: 2026/03/02 10:51:56 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

static int	is_space_or_oob(t_data *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return (1);
	if (game->map[y][x] == ' ')
		return (1);
	return (0);
}

static int	has_space_neighbor(t_data *game, int x, int y)
{
	if (is_space_or_oob(game, x + 1, y))
		return (1);
	if (is_space_or_oob(game, x - 1, y))
		return (1);
	if (is_space_or_oob(game, x, y + 1))
		return (1);
	if (is_space_or_oob(game, x, y - 1))
		return (1);
	return (0);
}

static int	all_zero_enclosed(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '0'
				&& has_space_neighbor(game, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	flood_fill(t_data *game)
{
	if (!game || !game->map)
		return (0);
	if (game->map_height <= 0 || game->map_width <= 0)
		return (0);
	if (!all_zero_enclosed(game))
	{
		error_msg(ERR_FLOOD, 1);
		return (0);
	}
	return (1);
}
