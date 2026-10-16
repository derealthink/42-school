/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:02:17 by aielo             #+#    #+#             */
/*   Updated: 2026/01/26 16:34:09 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	player_move_fw(t_data *game);
static int	player_move_bw(t_data *game);
static int	player_move_right(t_data *game);
static int	player_move_left(t_data *game);

int	player_move(t_data *game)
{
	int	moves;

	moves = 0;
	if (game->player.move_y == 1)
		moves = moves + player_move_fw(game);
	if (game->player.move_y == -1)
		moves = moves + player_move_bw(game);
	if (game->player.move_x == 1)
		moves = moves + player_move_right(game);
	if (game->player.move_x == -1)
		moves = moves + player_move_left(game);
	if (game->player.rotate != 0)
		moves = moves + player_rotate(game, game->player.rotate);
	return (moves);
}

static int	player_move_fw(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x + game->player.dir_x * SPEED;
	y = game->player.pos_y + game->player.dir_y * SPEED;
	return (is_valid_move(game, x, y));
}

static int	player_move_bw(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x - game->player.dir_x * SPEED;
	y = game->player.pos_y - game->player.dir_y * SPEED;
	return (is_valid_move(game, x, y));
}

static int	player_move_right(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x - game->player.dir_y * SPEED;
	y = game->player.pos_y + game->player.dir_x * SPEED;
	return (is_valid_move(game, x, y));
}

static int	player_move_left(t_data *game)
{
	double	x;
	double	y;

	x = game->player.pos_x + game->player.dir_y * SPEED;
	y = game->player.pos_y - game->player.dir_x * SPEED;
	return (is_valid_move(game, x, y));
}
