/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:02:49 by aielo             #+#    #+#             */
/*   Updated: 2026/03/10 13:04:21 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "cub3d.h"
# include "libft.h"
# include "exit.h"

int			is_empty_line(char *line);
int			is_space(char c);
char		**call_map(char *file);
char		**prep_id(char **map);
t_ulines	*parse_to_list(char *file);
int			get_map_height(char **map);
int			get_map_width(char **map);
void		free_list(t_ulines *head);
void		free_map(char **map);
int			val_txt_count(t_ulines *head, t_valid *d);
int			val_cc_count(t_ulines *head, t_valid *d);
int			str_has_digit(char *s);
int			is_mapc_val(char c);
int			val_mp_count(t_ulines *head);
int			is_dig_cc(t_ulines *head);
char		**map_config(t_data *game, t_ulines *head);
void		prep_pad(t_ulines *head);
char		**clean_colors(char **arr);
int			range_val(char **arr);
int			is_only_dig(char **arr);
int			list_to_struct(char *filename, t_data *game);
int			flood_fill(t_data *game);
int			cf_config(t_ulines *head, t_config *id);
int			cc_config(t_ulines *head, t_config *id);
int			ea_config(t_ulines *head, t_config *id);
int			we_config(t_ulines *head, t_config *id);
int			so_config(t_ulines *head, t_config *id);
int			no_config(t_ulines *head, t_config *id);
int			is_first_val(t_ulines *head);
int			is_last_val(t_ulines *head);
int			is_fline_val(t_ulines *head);
int			is_first_last_mapline_val(t_ulines *head);
void		free_split(char **arr);
int			final_parser(char *filename, t_data *game);
char		find_player_char(char **map);
int			validate_player(t_ulines *head);
int			color_check(t_ulines *head);

#endif
