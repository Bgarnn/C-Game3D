#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\v' || str[i] == '\f' || str[i] == '\n' || str[i]
		== '\r' || str[i] == '\t' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
// convert ascii (str) to ineger