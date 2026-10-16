/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uponci <uponci@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:07:15 by uponci            #+#    #+#             */
/*   Updated: 2025/05/17 16:07:19 by uponci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_all(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s || !(res = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = word_len(&s[i], c);
			if (!(res[j++] = ft_substr(s, i, len)))
				return (free_all(res, j), NULL);
			i += len;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}

int main(void)
{
    const char str[] = "hello0my0name0is";
    char c = '0';
    char **result = ft_split(str, c);
    size_t i = 0;

    if (result == NULL)
        printf("Error");
    while (result[i])
    {
        printf("word %zu: %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}
