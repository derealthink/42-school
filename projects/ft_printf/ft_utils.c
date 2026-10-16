#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_putnbr(int n)
{
	char	c;
	int	count;

	count = 0;
	
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	
	if (n < 0)
	{
		count += write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	count += write (1, &c, 1);
	return (count);
}
int	ft_u_putnbr(unsigned int n)
{
	char	c;
	int	count;

	count = 0;

	if (n > 9)
		count += ft_u_putnbr(n / 10);
	c = (n % 10) + '0';
	count += write (1, &c, 1);
	return (count);
}
int	ft_putchar(char c)
{	
	int	count;

	count = 0;
	count = write(1, &c, 1);
	return (count);
}

int	ft_putstr(char *s)
{
	int		i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

/*int	main()
{
	int printed = ft_putstr("ciao");
	write(1, "\n", 1);
	printf("Count: %d\n", printed);
}*/