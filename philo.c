#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*trd;
	int		n_philo;

	trd = (t_philo *)arg;
	while (1337)
	{

	
		pthread_mutex_lock(&trd->tprm->fork[trd->r_fork]);
		printf("[X] philo [%d] has taken right fork \n", trd->nbr_philo);
		pthread_mutex_lock(&trd->tprm->fork[trd->l_fork]);
		printf("[X] philo [%d] has taken left fork \n", trd->nbr_philo);
		printf("[X] philo [%d] is eating \n", trd->nbr_philo);
		usleep(50);
		pthread_mutex_unlock(&trd->tprm->fork[trd->r_fork]);
		pthread_mutex_unlock(&trd->tprm->fork[trd->l_fork]);
		printf("[X] philo [%d] is sleeping \n", trd->nbr_philo);
		usleep(50);
		
		// trd->t_philo->index++;
		// printf("///// --- philo : %d \t",  trd->nbr_philo);
		// printf("index =  ---\\\\\\\\ \n");
		// sleep(5);
		// pthread_mutex_unlock(&trd->lock);
	}
	return (NULL);
}
