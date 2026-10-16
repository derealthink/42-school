/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:15:02 by aielo             #+#    #+#             */
/*   Updated: 2026/02/19 17:23:08 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static void	free_texinfo(t_texinfo *textures);
static void	free_map(t_data *game);
static void	free_colors(t_data *game);

int	free_data(t_data *game)
{
	if (game->textures)
		free_tab((void **)game->textures);
	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
	free_texinfo(&game->texinfo);
	free_map(game);
	free_colors(game);
	return (1);
}

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_texinfo(t_texinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
}

static void	free_map(t_data *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

static void	free_colors(t_data *game)
{
	if (game->id.cc)
	{
		free_tab((void **)game->id.cc);
		game->id.cc = NULL;
	}
	if (game->id.cf)
	{
		free_tab((void **)game->id.cf);
		game->id.cf = NULL;
	}
}
