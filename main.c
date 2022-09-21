#include "philo.h"

void	creat_philo_threads(t_philo *stc)
{
	int		i;
	int		n_philo;
	t_param	*trd;

	i = 0;
	n_philo = stc->nbr_philo;
	trd = malloc(sizeof(t_param));
	trd->t_thread = malloc(sizeof(t_param) * n_philo);
	trd->t_philo = stc;
	trd->t_philo->index = 0;
	trd->lock = malloc(sizeof(pthread_mutex_init) * n_philo);
	while (n_philo > i)
	{
		trd->r_fork = 1;
		pthread_mutex_init(&trd->lock[trd->t_philo->index], NULL);
		pthread_create(&trd->t_thread[i], NULL, philo, trd);
		i++;
	}
	i = 0;
	while (n_philo > i)
	{
		pthread_join(trd->t_thread[i], NULL);
		i++;
	}
	
	
}

int main(int ac, char **arg)
{
	t_philo stc;

	if (ac < 4 || ac > 5 || check_arg(arg, &stc))	
		printf("Error\n");
	else
		creat_philo_threads(&stc);
	return (0);
}
