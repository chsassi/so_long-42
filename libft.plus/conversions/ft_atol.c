#include "libft.h"

long ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nl;

	i = 0;
	sign = 1;
	nl = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nl = nl * 10 + (str[i] - '0');
		i++;
	}
	return (nl * sign);
}
