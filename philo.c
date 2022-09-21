#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*trd;
	int		n_philo;

	trd = (t_philo *)arg;
	printf("here = %d \n", trd->nbr_philo);
	pthread_mutex_lock(&trd->lock);

	// trd->t_philo->index++;
	usleep(500);
	printf("///// --- philo : %d \t",  trd->nbr_philo);
	printf("index = %d ---\\\\\\\\ \n", trd->index);
	pthread_mutex_unlock(&trd->lock);

	return (NULL);
}
