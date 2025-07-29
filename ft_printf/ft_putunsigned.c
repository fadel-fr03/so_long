#include "ft_printf.h"

int	ft_putunsigned(unsigned long n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
