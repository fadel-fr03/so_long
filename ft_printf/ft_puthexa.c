#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char format)
{
	char			*base;
	unsigned int	num;
	int				i;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)n;
	if (num > ft_strlen(base) - 1)
		i += ft_puthexa(num / ft_strlen(base), format);
	i += ft_putchar(base[num % ft_strlen(base)]);
	return (i);
}
