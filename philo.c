/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:17 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/25 14:48:26 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_print()
{

}

void	*philo(void *arg)
{
	t_philo	*trd;
	int		n_philo;
	int		time_ms;

	trd = (t_philo *)arg;
	
	while (1337)
	{
		
		pthread_mutex_lock(&trd->tprm->fork[trd->r_fork]);
		printf("[%d ms] philo [%d] has taken right fork \n", get_time_consumed(trd), trd->nbr_philo);
		pthread_mutex_lock(&trd->tprm->fork[trd->l_fork]);
		printf("[%d ms] philo [%d] has taken left fork \n", get_time_consumed(trd), trd->nbr_philo);
		printf("[%d ms] philo [%d] is eating \n", get_time_consumed(trd), trd->nbr_philo);
		trd->end_tm = get_now_time_on_ms(trd->tprm->tv);
		ft_sleep(trd->tprm, trd->tprm->t_eat);
		pthread_mutex_unlock(&trd->tprm->fork[trd->r_fork]);
		pthread_mutex_unlock(&trd->tprm->fork[trd->l_fork]);
		printf("[%d ms] philo [%d] is sleeping \n", get_time_consumed(trd), trd->nbr_philo);
		usleep(trd->tprm->t_sleep * 1000);
		
	}
	return (NULL);
}
