/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:54 by aielo             #+#    #+#             */
/*   Updated: 2026/02/26 18:49:43 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_raycasting(t_data *game);

int	render(t_data *game)
{
	static double	last_frame = 0;
	static double	last_move_time = 0;
	double			now;
	double			frame_time;

	now = get_time_ms();
	if (last_frame == 0)
		last_frame = now;
	if (last_move_time == 0.0)
		last_move_time = now;
	frame_time = now - last_frame;
	if (now - last_move_time >= FRAME_RATE_MS)
	{
		game->player.has_moved = game->player.has_moved + player_move(game);
		last_move_time = now;
	}
	if (frame_time >= FRAME_RATE_MS)
	{
		render_frame(game);
		last_frame = now;
		game->player.has_moved = 0;
	}
	return (0);
}

void	render_frame(t_data *game)
{
	draw_background(game);
	render_raycasting(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.img,
		10, HEIGHT - (game->map_height * IMG_PXL) - 10);
	fflush(stdout);
}

void	draw_background(t_data *game)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			index = y * game->win_width + x;
			if (y < game->win_height / 2)
				game->frame.addr[index] = game->texinfo.hex_ceiling;
			else
				game->frame.addr[index] = game->texinfo.hex_floor;
			x++;
		}
		y++;
	}
}

static void	render_raycasting(t_data *game)
{
	init_texture_pixels(game);
	raycasting(&game->player, game);
	render_texture_to_frame(game);
}
