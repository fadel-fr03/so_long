#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

/*		returns absolute value of a long		*/
long	ft_abs(long n);

/*		for the %p specifier		*/
int		ft_putaddress(void *format);

/*		for the %c specifier		*/
int		ft_putchar(char c);

/*		for the %x or %X specifiers		*/
int		ft_puthexa(unsigned long n, char format);

/*		for the %d or %i specifier		*/
int		ft_putnbr(int n);

/*		for the %s specifier		*/
int		ft_putstr(char const *s);

/*		for the %u specifier		*/
int		ft_putunsigned(unsigned long n);

/*		the printf imitation using a variadic function		*/
int		ft_printf(const char *str, ...);

#endif
