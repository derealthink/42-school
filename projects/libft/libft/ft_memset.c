/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:26:03 by uponci            #+#    #+#             */
/*   Updated: 2025/05/09 17:26:05 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	byte_value;

	p = (unsigned char *)s;
	byte_value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		p[i] = byte_value;
		i++;
	}
	return (s);
}
