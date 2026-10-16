/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:58:38 by aielo             #+#    #+#             */
/*   Updated: 2026/03/02 14:13:19 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include "X11/keysym.h"
# include "exit.h"
# include "parsing.h"
# include "cub3d.h"

void	check_input(t_data *game);

void	set_player(t_data *game);
void	init_player_direction(t_data *game);

int		player_move(t_data *game);

int		is_valid_move(t_data *game, double x, double y);

int		player_rotate(t_data *game, int rotate);

#endif