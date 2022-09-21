#include "philo.h"

int check_arg(char **arg, t_param *stc)
{
	int	i;
	int	nbr;

	i = 1;
	while (arg[i])
	{
		nbr = ft_atoi(arg[i]);
		if (nbr < 0)
			return (1);
		if (i == 1)
		{
			stc->all_nbr_philo = nbr;
			stc->nbr_mutex = nbr;
			stc->nbr_fork = nbr;
		}
		else if (i == 2)
			stc->t_die = nbr;
		else if (i == 3)
			stc->t_eat = nbr;
		else if (i == 4)
			stc->t_sleep = nbr;
		else if (i == 5)
			stc->nbr_db_eat = nbr;
		i++;
	}
	return (0);
}
