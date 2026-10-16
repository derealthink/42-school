/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:33:39 by aielo             #+#    #+#             */
/*   Updated: 2026/02/19 17:25:08 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdio.h>
# include "libft.h"
# include "cub3d.h"

int		error_msg(char *description, int exit_code);

void	clean_exit(t_data *game, int exit_code);
int		quit_game(t_data *game);

int		free_data(t_data *game);
void	free_tab(void **tab);
void	free_config(t_data *game);

#endif