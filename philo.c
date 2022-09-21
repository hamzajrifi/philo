#include "philo.h"

void	*philo(void *arg)
{
	t_param	*trd;
	int		n_philo;

	trd = (t_param *)arg;
	pthread_mutex_lock(&trd->lock);

	trd->t_philo->index++;

	n_philo = trd->t_philo->nbr_philo;
	printf("philo : %d \n", n_philo);
	printf("index = %d \n", trd->t_philo->index);
	pthread_mutex_unlock(&trd->lock);

	return (NULL);
}
