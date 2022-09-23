#include "philo.h"

void	creat_philo_threads(t_param *trd)
{
	int		i;
	int		n_philo;

	i = 0;
	n_philo = trd->all_nbr_philo;
	trd->db_philo = malloc(sizeof(t_philo) * n_philo);
	trd->i = 0;
	insialise_forks(trd);
	while (n_philo > i)
	{
		trd->db_philo[i].nbr_philo = i;
		pthread_mutex_init(trd->db_philo[i].m_fork, NULL);
		trd->i = i;
		pthread_create(&trd->db_philo[i].t_thread, NULL, philo, &trd->db_philo[i]);
		i++;
	}
	i = 0;
	while (n_philo > i)
	{
		pthread_join(trd->db_philo[i].t_thread, NULL);
		i++;
	}
}

int main(int ac, char **arg)
{
	t_param stc;

	if (ac < 4 || ac > 5 || check_arg(arg, &stc))	
		printf("Error\n");
	else
		creat_philo_threads(&stc);
	return (0);
}
