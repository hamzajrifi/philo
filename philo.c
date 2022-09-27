/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:17 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/27 23:48:56 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_print(t_philo *ph, char *str)
{
	pthread_mutex_lock(&ph->tprm->print);
	if (!(ph->tprm->end_programme))
		printf("[%d ms] philo [%d] %s\n", get_time_consumed(ph), ph->nbr_philo + 1, str);
	pthread_mutex_unlock(&ph->tprm->print);
}

void	*philo(void *arg)
{
	t_philo	*trd;

	trd = (t_philo *)arg;
	while (1337)
	{
		if(trd->tprm->end_programme)
			break;
		pthread_mutex_lock(&trd->tprm->fork[trd->r_fork]);
			my_print(trd, "has taken right fork");
		pthread_mutex_lock(&trd->tprm->fork[trd->l_fork]);
			my_print(trd, "has taken left fork");
			my_print(trd, "is eating");
			ft_sleep(trd->tprm, trd->tprm->t_eat);// time to eating
			my_print(trd, "is sleeping");
		pthread_mutex_lock(&trd->tprm->lock);
			trd->end_tm = get_now_time_on_ms();
		pthread_mutex_unlock(&trd->tprm->lock);
			// trd->end_tm = get_now_time_on_ms();
		pthread_mutex_unlock(&trd->tprm->fork[trd->l_fork]);
		pthread_mutex_unlock(&trd->tprm->fork[trd->r_fork]);
			ft_sleep(trd->tprm, trd->tprm->t_sleep);// time to sleep
			my_print(trd, "is thinking");

	}
	return (NULL);
}


// void	*philo(void *arg)
// {
// 	t_philo	*trd;

// 	trd = (t_philo *)arg;
// 	// while (trd->nbr_meal_eat >= -1 && trd->nbr_meal_eat < tprm->nbr_meals)
// 	while(22)
// 	{
// 		pthread_mutex_lock(&trd->tprm->fork[trd->r_fork]);
// 			my_print(trd, "has taken right fork");
// 		pthread_mutex_lock(&trd->tprm->fork[trd->l_fork]);
// 			my_print(trd, "has taken left fork");
// 		pthread_mutex_lock(&trd->tprm->lock);
// 			my_print(trd, "is eating");
// 			trd->end_tm = get_now_time_on_ms();
// 			ft_sleep(trd->tprm, trd->tprm->t_eat);// time to eating
// 		// if (trd->tprm->nbr_meals > 0)
// 			// (trd->nbr_meal_eat)++;
// 			my_print(trd, "is sleeping");
// 			trd->end_tm = get_now_time_on_ms();
// 		pthread_mutex_unlock(&trd->tprm->lock);
// 		pthread_mutex_unlock(&trd->tprm->fork[trd->l_fork]);
// 		pthread_mutex_unlock(&trd->tprm->fork[trd->r_fork]);
// 		// pthread_mutex_lock(&trd->tprm->lock);
		
// 		ft_sleep(trd->tprm, trd->tprm->t_sleep);// time to sleep
// 		my_print(trd, "is thinking");
// 		// pthread_mutex_unlock(&trd->tprm->lock);
		
// 	}
// 	return (NULL);
// }
