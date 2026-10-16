#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	va_list args;

	va_start(args, str);
	total = 0;
	i = 0;
	while (str[i])
{
    if (str[i] != '%')
        total += write(1, &str[i++], 1);
    else if (str[i + 1])
        total += ft_sort_type_param(str[i + 1], &args), i += 2;
    else
        break;
}
	va_end(args);
	return (total);
}

int	ft_sort_type_param(char  c,  va_list *args)
{
	int	printed;

	printed = 0;
	if (c == 'c')
		printed = ft_putchar(va_arg(*args, int)); 
	if (c == 's')
		printed = ft_putstr(va_arg(*args, char *)); 
	if (c == 'p')
		printed = ft_hex_p(va_arg(*args, void *)); 
	if (c == 'd')
		printed = ft_putnbr(va_arg(*args, int)); 
	if (c == 'i')
		printed = ft_putnbr(va_arg(*args, int));
	if (c == 'u')
		printed = ft_u_putnbr(va_arg(*args, unsigned int)); 
	if (c == 'x')
		printed = ft_hex_low(va_arg(*args, unsigned int));
	if (c == 'X')
		printed = ft_hex_up(va_arg(*args, unsigned int));
	if (c == '%')
		printed = write(1, "%", 1);
	return (printed);
}
