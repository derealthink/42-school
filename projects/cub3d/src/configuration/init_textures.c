/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:40:13 by aielo             #+#    #+#             */
/*   Updated: 2026/02/13 12:20:27 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"

void	init_textures(t_data *game)
{
	game->texinfo.north = game->id.no;
	game->id.no = NULL;
	game->texinfo.south = game->id.so;
	game->id.so = NULL;
	game->texinfo.east = game->id.ea;
	game->id.ea = NULL;
	game->texinfo.west = game->id.we;
	game->id.we = NULL;
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		clean_exit(game, error_msg(ERR_MALLOC, 1));
	game->textures[NORTH] = xpm_to_img(game, game->texinfo.north);
	game->textures[SOUTH] = xpm_to_img(game, game->texinfo.south);
	game->textures[EAST] = xpm_to_img(game, game->texinfo.east);
	game->textures[WEST] = xpm_to_img(game, game->texinfo.west);
}

int	*xpm_to_img(t_data *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(game, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * game->texinfo.size * game->texinfo.size);
	if (!buffer)
		clean_exit(game, error_msg(ERR_MALLOC, 1));
	y = 0;
	while (y < game->texinfo.size)
	{
		x = 0;
		while (x < game->texinfo.size)
		{
			buffer[y * game->texinfo.size + x]
				= tmp.addr[y * game->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}
