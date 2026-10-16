/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:58:38 by aielo             #+#    #+#             */
/*   Updated: 2026/02/13 12:36:20 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGURATION_H
# define CONFIGURATION_H

# include <stdlib.h>
# include "cub3d.h"
# include "exit.h"

void	init_data(t_data *game);
void	init_img_data(t_img *img);
void	init_ray(t_ray *ray);
void	init_texinfo(t_texinfo *textures);

void	init_mlx(t_data *game);
void	init_image(t_data *game, t_img *image, int width, int height);
void	init_texture_img(t_data *game, t_img *image, char *path);

void	init_config(t_config *id);
void	init_ulines(t_ulines *list);
void	init_valid(t_valid *d);

void	init_textures(t_data *game);
int		*xpm_to_img(t_data *game, char *path);

#endif