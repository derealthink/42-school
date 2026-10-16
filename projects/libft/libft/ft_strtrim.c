/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:06:56 by uponci            #+#    #+#             */
/*   Updated: 2025/05/17 16:07:02 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	start_index(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	return (i);
}

static size_t	end_index(const char *s1, const char *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0 && in_set(s1[len - 1], set))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	start = start_index(s1, set);
	end = end_index(s1, set);
	if (end <= start)
		return (ft_strdup(""));
	trimmed = (char *)malloc(end - start + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}
