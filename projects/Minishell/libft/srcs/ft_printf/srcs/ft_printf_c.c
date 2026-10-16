/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aielo <aielo@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:21:22 by aielo             #+#    #+#             */
/*   Updated: 2026/04/21 16:52:42 by aielo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_identifier_c(va_list *arg_list, t_flags *flag)
{
	int		printed;
	char	c;

	printed = 0;
	c = (char)(va_arg(*arg_list, int));
	if (!flag->left)
	{
		printed += ft_flag_width(flag, 1);
		ft_putchar_fd(c, 1);
		printed += 1;
	}
	else
	{
		ft_putchar_fd(c, 1);
		printed += 1;
		printed += ft_flag_width(flag, 1);
	}
	return (printed);
}
