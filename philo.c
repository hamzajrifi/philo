/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:17 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/24 20:52:37 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*trd;
	int		n_philo;
	int		time_ms;

	trd = (t_philo *)arg;
	
	while (1337)
	{
		pthread_mutex_lock(&trd->tprm->fork[trd->r_fork]);
		time_ms = get_now_time_on_ms(trd);
		printf("[%dms] philo [%d] has taken right fork \n", time_ms, trd->nbr_philo);
		pthread_mutex_lock(&trd->tprm->fork[trd->l_fork]);
		printf("[%dms] philo [%d] has taken left fork \n", time_ms, trd->nbr_philo);
		printf("[%dms] philo [%d] is eating \n", time_ms, trd->nbr_philo);
		usleep(trd->tprm->t_eat * 1000);
		pthread_mutex_unlock(&trd->tprm->fork[trd->r_fork]);
		pthread_mutex_unlock(&trd->tprm->fork[trd->l_fork]);
		printf("[%dms] philo [%d] is sleeping \n", time_ms, trd->nbr_philo);
		usleep(trd->tprm->t_sleep * 1000);
		
	}
	return (NULL);
}
