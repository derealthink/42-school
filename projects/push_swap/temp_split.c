#include "push_swap.h"

static int	count_words(char *str)
{
	int w = 0;
	int i = 0;
	int f = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && f == 0)
		{
			f = 1;
			w++;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			f = 0;
		i++;
	}
	return w;
}

static int	word_len(char *str)
{
	int	i = 0;
	int	len = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
	{
		len++;
		i++;
	}
	return (len);
}

static char	*sub_str(char *str)
{
	int size = word_len(str);
	char *res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}



char	**ft_split(char *str)
{
	char **arr;
	char *word;

	int words = count_words(str);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	int i = 0;
	int	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i] != '\0')
			{
				word = sub_str(&str[i]);
				if (!word)
					return (NULL);
				arr[j++] = word;
				i = i + word_len(&str[i]);
			}
	}
	arr[j] = NULL;
	return (arr);
}