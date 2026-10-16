/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:54:08 by aielo             #+#    #+#             */
/*   Updated: 2026/02/23 14:19:53 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_map_to_buffer(t_data *game);
static void	draw_tile_to_buffer(t_data *game, size_t x, size_t y);
static void	draw_rectangle(t_data *game, t_rect rect);

void	render_minimap(t_data *game)
{
	size_t	y;
	size_t	x;
	int		index;

	y = 0;
	while (y < (size_t)game->map_height * IMG_PXL)
	{
		x = 0;
		while (x < (size_t)game->map_width * IMG_PXL)
		{
			index = y * game->minimap.width + x;
			game->minimap.addr[index] = MAP_BG_COLOR;
			x++;
		}
		y++;
	}
	draw_map_to_buffer(game);
	draw_rectangle(game, (t_rect){game->player.pos_x * IMG_PXL,
		game->player.pos_y * IMG_PXL, IMG_PXL / 2, MAP_PLAYER_COLOR});
}

static void	draw_map_to_buffer(t_data *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)game->map_height)
	{
		x = 0;
		while (x < (size_t)game->map_width && game->map[y][x] != '\0')
		{
			draw_tile_to_buffer(game, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_tile_to_buffer(t_data *game, size_t x, size_t y)
{
	if (game->map[y][x] == '1')
		draw_rectangle(game, (t_rect){x * IMG_PXL, y * IMG_PXL,
			IMG_PXL / 2, MAP_WALL_COLOR});
	else if (game->map[y][x] == ' ')
		draw_rectangle(game, (t_rect){x * IMG_PXL, y * IMG_PXL,
			IMG_PXL, MAP_BG_COLOR});
	else if (game->map[y][x] == '0')
		draw_rectangle(game, (t_rect){x * IMG_PXL, y * IMG_PXL,
			IMG_PXL, MAP_FLOOR_COLOR});
	else if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
		|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
		draw_rectangle(game, (t_rect){x * IMG_PXL, y * IMG_PXL,
			IMG_PXL, MAP_FLOOR_COLOR});
}

static void	draw_rectangle(t_data *game, t_rect rect)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < rect.size)
	{
		j = 0;
		while (j < rect.size)
		{
			if ((rect.y + j) >= 0 && (rect.y + j) < game->minimap.height
				&& (rect.x + i) >= 0 && (rect.x + i) < game->minimap.width)
			{
				index = (rect.y + j) * game->minimap.width + (rect.x + i);
				game->minimap.addr[index] = rect.color;
			}
			j++;
		}
		i++;
	}
}
