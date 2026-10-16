#include "push_swap.h"

long 	ft_atol_strict(char *str)
{
	int		i;      // no error messages on input and overflow check subject about this.
	int		sign;
	long 	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!str[i])
		exit (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			exit (1);
		num = num * 10 + (str[i++] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > (long)INT_MAX + 1))
			exit (1);
	}
	return (num * sign);
}
