/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:20:04 by uponci            #+#    #+#             */
/*   Updated: 2025/05/14 16:20:06 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sr;
	size_t				i;

	sr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sr[i] == (unsigned char)c)
			return ((void *)(sr + i));
		i++;
	}
	return (NULL);
}
