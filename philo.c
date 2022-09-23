#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*trd;
	int		n_philo;

	trd = (t_philo *)arg;
	printf("left philo = %d \n", trd->l_fork);
	printf("right philo = %d \n", trd->r_fork);
	// pthread_mutex_lock(trd->m_fork);
	// trd->t_philo->index++;
	// printf("///// --- philo : %d \t",  trd->nbr_philo);
	// printf("index =  ---\\\\\\\\ \n");
	// sleep(5);
	// pthread_mutex_unlock(&trd->lock);

	return (NULL);
}
