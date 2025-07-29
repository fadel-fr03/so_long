#include "ft_printf.h"

static int	nb_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = ft_abs(n);
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
	return (nb_len(n));
}
