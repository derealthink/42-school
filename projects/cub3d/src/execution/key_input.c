/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:24:36 by aielo             #+#    #+#             */
/*   Updated: 2026/01/26 18:28:36 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	key_press_handler(int keycode, t_data *game);
static int	key_release_handler(int keycode, t_data *game);

void	check_input(t_data *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, quit_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press_handler, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release_handler, game);
}

static int	key_press_handler(int keycode, t_data *game)
{
	if (keycode == XK_Escape)
		quit_game(game);
	if (keycode == XK_Left)
		game->player.rotate = -1;
	if (keycode == XK_Right)
		game->player.rotate = 1;
	if (keycode == XK_w)
		game->player.move_y = 1;
	if (keycode == XK_a)
		game->player.move_x = -1;
	if (keycode == XK_s)
		game->player.move_y = -1;
	if (keycode == XK_d)
		game->player.move_x = 1;
	return (0);
}

static int	key_release_handler(int keycode, t_data *game)
{
	if (keycode == XK_w && game->player.move_y == 1)
		game->player.move_y = 0;
	if (keycode == XK_s && game->player.move_y == -1)
		game->player.move_y = 0;
	if (keycode == XK_a && game->player.move_x == -1)
		game->player.move_x = 0;
	if (keycode == XK_d && game->player.move_x == 1)
		game->player.move_x = 0;
	if (keycode == XK_Left && game->player.rotate < 0)
		game->player.rotate = 0;
	if (keycode == XK_Right && game->player.rotate > 0)
		game->player.rotate = 0;
	return (0);
}
