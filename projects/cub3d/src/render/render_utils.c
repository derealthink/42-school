/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:17:57 by aielo             #+#    #+#             */
/*   Updated: 2026/02/13 11:21:24 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	frame_put_pixel(t_img *img, int x, int y, int color)
{
	int	index;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	index = y * img->width + x;
	img->addr[index] = color;
}

void	render_texture_to_frame(t_data *game)
{
	int	y;
	int	x;
	int	index;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			index = y * game->win_width + x;
			if (game->texture_pixels[y][x] > 0)
				game->frame.addr[index] = game->texture_pixels[y][x];
			x++;
		}
		y++;
	}
}
