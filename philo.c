/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:17 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/26 21:53:35 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_print(t_philo *ph, char *str)
{
	pthread_mutex_lock(&ph->tprm->print);
	if (!(ph->tprm->end_programme))
		printf("[%d ms] philo [%d] %s\n", get_time_consumed(ph), ph->nbr_philo, str);
	pthread_mutex_unlock(&ph->tprm->print);
}

void	*philo(void *arg)
{
	t_philo	*trd;
	t_param	*tprm;

	trd = (t_philo *)arg;
	tprm = trd->tprm;
	while (1337)
	{
		
		pthread_mutex_lock(&tprm->fork[trd->r_fork]);
		my_print(trd, "has taken right fork");
		pthread_mutex_lock(&tprm->fork[trd->l_fork]);
		my_print(trd, "has taken left fork");
		pthread_mutex_lock(&tprm->lock);
		my_print(trd, "is eating");
		trd->end_tm = get_now_time_on_ms();
		ft_sleep(tprm, tprm->t_eat);// time to eating
		my_print(trd, "is sleeping");
		trd->end_tm = get_now_time_on_ms();
		pthread_mutex_unlock(&tprm->lock);
		pthread_mutex_unlock(&tprm->fork[trd->l_fork]);
		pthread_mutex_unlock(&tprm->fork[trd->r_fork]);
		ft_sleep(tprm, tprm->t_sleep);// time to sleep
		my_print(trd, "is thinking");

	}
	return (NULL);
}
