#include "push_swap.h"

int	num_check_wq(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 32 || str[i] == '+' || str[i] == '-'))
		{	
			write (2, "Input Error\n", 13);
			return (0);
		}
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+' || str[i + 1] == '-'))
		{
			write (2, "Input Error\n", 13);
			return (0);
		}
		i++;
	}
	return (1);	
}
int	arg_count(char *str)
{
	int	i;
	int	isarg;
	int	count;

	i = 0;
	isarg = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
		{
			if (!isarg)
			{
				count++;
				isarg = 1;
			}
		}
		else if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			isarg = 0;
		else
			isarg = 0; 
		i++;
	}
	return (count);
}


int	*parse_wq(char *str)
{
	char	**carr;
	int		*iarr;
	int		count;
	int		i;
	
	if (!num_check_wq(str))
		return (NULL);
	count = arg_count(str);
	carr = ft_split(str);
	iarr = malloc(sizeof(int) * count);
	if (!iarr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		iarr[i] = (int)ft_atol_strict(carr[i]);
		i++;
	}
	if (!has_doubles(iarr, count))
	{
		free(iarr);
		return (NULL);
	}
	free_split(carr);	
return (iarr);
}

int	has_doubles(int	*arr, int count)
{
	int	i;
	int j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	*parse_ma(char **argv, int count)
{
	int	*iarr;
	int	i;

	i = 0;
	while (i < count)
	{
		if (!num_check_wq(argv[i]))
			return (NULL);
		i++;
	}
	iarr = malloc(sizeof(int) * count);
	if (!iarr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		iarr[i] = (int)ft_atol_strict(argv[i]);
		i++;
	}
	if (!has_doubles(iarr, count))
	{
		free(iarr);
		return (NULL);
	}	
	return (iarr);	
}
