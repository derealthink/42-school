/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:00:45 by uponci            #+#    #+#             */
/*   Updated: 2025/05/18 17:00:46 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digits(unsigned int nb)
{
	size_t		count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static void	fill_str(char *s, int n, unsigned int nb, size_t len)
{
	size_t	j;

	s[len] = '\0';
	if (n < 0)
		s[0] = '-';
	if (nb == 0)
		s[len - 1] = '0';
	else
	{
		j = len - 1;
		while (nb > 0)
		{
			s[j] = (nb % 10) + '0';
			nb = nb / 10;
			j--;
		}
	}
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	size_t			len;
	char			*result;

	if (n < 0)
		nb = (unsigned int)(-(long)n);
	else
		nb = (unsigned int)n;
	len = digits(nb);
	if (n < 0)
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	fill_str(result, n, nb, len);
	return (result);
}
