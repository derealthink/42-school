
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_u_putnbr(unsigned int n);
int	ft_putchar(char c);
int	ft_printf(const char *str, ...);
int	ft_sort_type_param(char  c,  va_list *args);
int	ft_hex_up(unsigned int num);
int	ft_hex_low(unsigned int num);
int	ft_hex_p(void *ptr);



#endif

