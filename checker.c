#include "philo.h"

int check_arg(char **arg)
{
	int	i;
	int 	tab[4];
	int	nbr;

	i = 1;
	while (arg[i])
	{
		nbr = ft_atoi(arg[i]);
		if (nbr < 0)
			return (1);
		tab[i - 1] = nbr;  
		printf("numbre [%d] : %d\n", i - 1, tab[i - 1]);
		i++;
	}
	return (0);
}
