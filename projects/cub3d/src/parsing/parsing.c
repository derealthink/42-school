/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:51:29 by uponci            #+#    #+#             */
/*   Updated: 2026/03/05 16:43:31 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "configuration.h"

int	validate_all(t_valid *d, t_ulines *head)
{
	if (!val_txt_count(head, d))
		return (0);
	if (!val_cc_count(head, d))
		return (0);
	if (!is_dig_cc(head))
		return (0);
	if (!color_check(head))
		return (0);
	if (!val_mp_count(head))
		return (0);
	if (!is_first_val(head))
		return (0);
	if (!is_last_val(head))
		return (0);
	if (!is_fline_val(head))
		return (0);
	if (!is_first_last_mapline_val(head))
		return (0);
	if (!validate_player(head))
		return (0);
	return (1);
}

int	caller_id(t_ulines *head, t_config *id)
{
	if (!no_config(head, id) || !so_config(head, id)
		|| !ea_config(head, id) || !we_config(head, id))
	{
		error_msg(ERR_PARSE_TEX, 1);
		free_list(head);
		return (0);
	}
	if (!cc_config(head, id) || !cf_config(head, id))
	{
		error_msg(ERR_PARSE_COLOR, 1);
		free_list(head);
		return (0);
	}
	return (1);
}

int	list_to_struct(char *filename, t_data *game)
{
	t_ulines	*head;
	t_valid		d;

	init_valid(&d);
	head = parse_to_list(filename);
	if (!head)
		return (0);
	if (!validate_all(&d, head))
	{
		free_list(head);
		error_msg(ERR_NO_VALIDATE, 1);
		return (0);
	}
	if (!caller_id(head, &game->id))
		return (0);
	prep_pad(head);
	game->map = map_config(game, head);
	if (!game->map)
	{
		free_list(head);
		return (0);
	}
	free_list(head);
	return (1);
}
