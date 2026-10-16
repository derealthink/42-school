/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:52:01 by uponci            #+#    #+#             */
/*   Updated: 2025/06/18 12:52:03 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

int	ft_hex_up(unsigned int num)
{
	char			buffer[16];
	char			hex_map[] = "0123456789ABCDEF";
	int				i;
	int				count;

	if (num == 0)
		return write(1, "0", 1);
	i = 0;
	while (num > 0)
	{
		buffer[i++] = hex_map[num % 16];
		num /= 16;
	}
	count = 0;
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return count;
}

int	ft_hex_low(unsigned int num)
{
	char			buffer[16];
	char			hex_map[] = "0123456789abcdef";
	int				i;
	int				count;

	count = 0;
	if (num == 0)
		return  (count = write(1, "0", 1));
	i = 0;
	while (num > 0)
	{
		buffer[i++] = hex_map[num % 16];
		num /= 16;
	}
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return count;
}

int	ft_hex_p(void *ptr)
{
	unsigned long	val;
	int				p;
	char			buffer[16];
	char			hex_map[] = "0123456789abcdef";
	int				i;

	p = 0;
	p += write(1, "0x", 2); 
	val = (unsigned long) ptr;
	if (val == 0)
		return (p + write(1, "0", 1));
	i = 0;
	while (val > 0)
	{
		buffer[i++] = hex_map[val % 16];
		val /= 16;
	}
	while (--i >= 0)
		p += write(1, &buffer[i], 1);
	return (p);
}
