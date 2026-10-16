/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:03:03 by uponci            #+#    #+#             */
/*   Updated: 2025/05/14 18:03:06 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*temp;
	size_t	i;
	size_t	tot_size;

	tot_size = nmeb * size;
	temp = (char *)malloc(tot_size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < tot_size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
