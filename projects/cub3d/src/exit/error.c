/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:07:30 by aielo             #+#    #+#             */
/*   Updated: 2026/01/26 16:27:47 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	error_msg(char *description, int exit_code)
{
	ft_putstr_fd("cub3D: Error", 2);
	if (description)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(description, 2);
	}
	ft_putstr_fd("\n", 2);
	return (exit_code);
}
