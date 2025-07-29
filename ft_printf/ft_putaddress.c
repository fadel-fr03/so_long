#include "ft_printf.h"

static int	print(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n > ft_strlen(base) - 1)
		len += print(n / ft_strlen(base), base);
	len += ft_putchar(*(base + (n % ft_strlen(base))));
	return (len);
}

int	ft_putaddress(void *ptr)
{
	unsigned long	n;
	const char		*base;
	int				len;

	n = (unsigned long)ptr;
	base = "0123456789abcdef";
	len = ft_putstr("0x");
	len += print(n, base);
	return (len);
}
