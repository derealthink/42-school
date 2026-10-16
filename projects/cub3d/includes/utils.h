/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:31:49 by aielo             #+#    #+#             */
/*   Updated: 2026/02/26 18:47:47 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "cub3d.h"
# include "libft.h"

double			get_time_ms(void);
unsigned long	rgb_to_hex(char **rgb);
void			print_infos(void);

#endif