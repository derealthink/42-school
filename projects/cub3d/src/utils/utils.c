/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:21:44 by aielo             #+#    #+#             */
/*   Updated: 2026/02/13 12:31:19 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	check_rgb_limit(int *color);

double	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

unsigned long	rgb_to_hex(char **rgb)
{
	int				r;
	int				g;
	int				b;
	unsigned long	hex;

	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (0);
	r = ft_atoi(rgb[0]);
	check_rgb_limit(&r);
	g = ft_atoi(rgb[1]);
	check_rgb_limit(&g);
	b = ft_atoi(rgb[2]);
	check_rgb_limit(&b);
	hex = (r << 16) | (g << 8) | b;
	return (hex);
}

static void	check_rgb_limit(int *color)
{
	if (*color < 0)
		*color = 0;
	if (*color > 255)
		*color = 255;
}

void	print_infos(void)
{
	printf("\n");
	printf("             _    ____  _____  \n");
	printf("            | |  |___ \\|  __ \\ \n");
	printf("   ___ _   _| |__  __) | |  | |\n");
	printf("  / __| | | | '_ \\|__ <| |  | |\n");
	printf(" | (__| |_| | |_) |__) | |__| |\n");
	printf("  \\___|\\__,_|_.__/____/|_____/ \n");
	printf("\n");
	printf("\tW: move forward\t");
	printf("\tS: move backward\n");
	printf("\tA: move left\t");
	printf("\tD: move right\n");
	printf("\t<: rotate left\t");
	printf("\t>: rotate right\n");
	printf("\n");
}
