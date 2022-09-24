#include "philo.h"

void	insialise_forks(t_param *ph_stc)
{
	int	i;

	i = 0;
	ph_stc->fork = malloc(sizeof(pthread_mutex_t) * ph_stc->all_nbr_philo);
	while (i < ph_stc->all_nbr_philo)
	{
		pthread_mutex_init(&ph_stc->fork[i], NULL);
		ph_stc->db_philo[i].r_fork = i;
		ph_stc->db_philo[i].l_fork = ((i + 1) % ph_stc->all_nbr_philo);
		i++;
	}
}

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
