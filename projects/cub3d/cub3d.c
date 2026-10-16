/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:12:14 by aielo             #+#    #+#             */
/*   Updated: 2026/03/09 18:41:43 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "configuration.h"
#include "execution.h"
#include "exit.h"
#include "parsing.h"
#include "render.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2 || ft_strlen(argv[1]) < 3)
		return (error_msg(ERR_WRONG_INPUT, 1));
	init_data(&game);
	if (final_parser(argv[1], &game))
	{
		set_player(&game);
		game.texinfo.hex_ceiling = rgb_to_hex(game.id.cc);
		game.texinfo.hex_floor = rgb_to_hex(game.id.cf);
		init_mlx(&game);
		init_textures(&game);
		init_texture_pixels(&game);
		print_infos();
		check_input(&game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_loop(game.mlx);
		return (0);
	}
	free_data(&game);
	free_config(&game);
	return (0);
}
