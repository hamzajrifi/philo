#include "philo.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	signe;
	long	rest;

	i = 0;
	signe = 1;
	rest = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		rest = rest * 10 + (str[i] - 48);
		if (rest < -2147483648 && signe == -1)
			return (0);
		if (rest > 2147483647 && signe == 1)
			return (-1);
		i++;
	}
	return (rest * signe);
}
