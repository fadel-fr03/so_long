#include "ft_printf.h"

int	ft_putstr(char const *s)
{
	if (!s)
		return (write(1, "(null)", ft_strlen("(null)")));
	return (write(1, s, ft_strlen(s)));
}
