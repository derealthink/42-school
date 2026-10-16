/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:27:06 by aielo             #+#    #+#             */
/*   Updated: 2026/02/23 15:59:19 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	clean_exit(t_data *game, int exit_code)
{
	if (!game)
		exit(exit_code);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free_data(game);
	printf("\n");
	exit(exit_code);
}

int	quit_game(t_data *game)
{
	clean_exit(game, 0);
	return (0);
}

void	free_config(t_data *game)
{
	if (game->id.no)
		free(game->id.no);
	if (game->id.so)
		free(game->id.so);
	if (game->id.ea)
		free(game->id.ea);
	if (game->id.we)
		free(game->id.we);
}
