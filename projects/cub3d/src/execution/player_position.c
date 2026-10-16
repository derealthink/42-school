/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:37:37 by aielo             #+#    #+#             */
/*   Updated: 2026/02/13 11:09:17 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static bool	is_valid_position(t_data *game, double x, double y);
static bool	is_valid_in_map(t_data *game, double x, double y);
static bool	wall_collision(t_data *game, double x, double y);

int	is_valid_move(t_data *game, double x, double y)
{
	int	moves;

	moves = 0;
	if (is_valid_position(game, x, game->player.pos_y))
	{
		game->player.pos_x = x;
		moves = 1;
	}
	if (is_valid_position(game, game->player.pos_x, y))
	{
		game->player.pos_y = y;
		moves = 1;
	}
	return (moves);
}

static bool	is_valid_position(t_data *game, double x, double y)
{
	if (!is_valid_in_map(game, x, y))
		return (false);
	if (!wall_collision(game, x, y))
		return (false);
	return (true);
}

static bool	is_valid_in_map(t_data *game, double x, double y)
{
	if ((int)x < 0 || (int)x >= game->map_width)
		return (false);
	if ((int)y < 0 || (int)y >= game->map_height)
		return (false);
	return (true);
}

static bool	wall_collision(t_data *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (game->map[map_y][map_x] == '1')
		return (false);
	return (true);
}
