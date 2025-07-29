#include "ft_printf.h"

long	ft_abs(long n)
{
	long	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}
