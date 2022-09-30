/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:17 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/28 22:38:02 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_print(t_philo *ph, char *str)
{
	pthread_mutex_lock(&ph->tprm->print);
	if (!(ph->tprm->end_programme))
		printf("[%d ms] philo [%d] %s\n",
			get_time_consumed(ph),
			ph->nbr_philo + 1, str);
	pthread_mutex_unlock(&ph->tprm->print);
}

static int	check_if_end(t_philo *trd)
{
	pthread_mutex_lock(&trd->tprm->lock);
	if (trd->tprm->end_programme || (trd->tprm->nbr_meals
			&& (trd->nbr_meal_eat >= trd->tprm->nbr_meals)))
	{
		pthread_mutex_unlock(&trd->tprm->lock);
		return (1);
	}
	pthread_mutex_unlock(&trd->tprm->lock);
	return (0);
}

void	*philo(void *arg)
{
	t_philo	*trd;

	trd = (t_philo *)arg;
	while (1337)
	{
		if (check_if_end(trd))
			break ;
		pthread_mutex_lock(&trd->tprm->fork[trd->r_fork]);
		my_print(trd, "has taken right fork");
		pthread_mutex_lock(&trd->tprm->fork[trd->l_fork]);
		my_print(trd, "has taken left fork");
		my_print(trd, "is eating");
		pthread_mutex_lock(&trd->tprm->lock);
		trd->end_tm = get_now_time_on_ms();
		(trd->nbr_meal_eat)++;
		pthread_mutex_unlock(&trd->tprm->lock);
		ft_sleep(trd, trd->tprm->t_eat);
		my_print(trd, "is sleeping");
		pthread_mutex_unlock(&trd->tprm->fork[trd->l_fork]);
		pthread_mutex_unlock(&trd->tprm->fork[trd->r_fork]);
		ft_sleep(trd, trd->tprm->t_sleep);
		my_print(trd, "is thinking");
	}
	return (NULL);
}
