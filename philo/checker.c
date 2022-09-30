/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:13:58 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/28 22:13:04 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_now_time_on_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	get_time_consumed(t_philo *trd)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (get_now_time_on_ms() - trd->tprm->start_time);
}

void	insialise_forks(t_param *ph_stc)
{
	int	i;

	i = 0;
	ph_stc->fork = malloc(sizeof(pthread_mutex_t) * ph_stc->all_nbr_philo);
	pthread_mutex_init(&ph_stc->lock, NULL);
	pthread_mutex_init(&ph_stc->print, NULL);
	ph_stc->end_programme = 0;
	ph_stc->x_meals = 0;
	while (i < ph_stc->all_nbr_philo)
	{
		pthread_mutex_init(&ph_stc->fork[i], NULL);
		ph_stc->db_philo[i].nbr_meal_eat = 0;
		ph_stc->db_philo[i].r_fork = i;
		ph_stc->db_philo[i].l_fork = ((i + 1) % ph_stc->all_nbr_philo);
		i++;
	}
	ph_stc->start_time = get_now_time_on_ms();
}

int	check_arg(char **arg, t_param *stc)
{
	int	i;

	i = 1;
	stc->nbr_meals = 0;
	while (arg[i])
	{
		if (ft_atoi(arg[i]) <= 0)
			return (1);
		if (i == 1)
		{
			stc->all_nbr_philo = ft_atoi(arg[i]);
			stc->nbr_mutex = ft_atoi(arg[i]);
			stc->nbr_fork = ft_atoi(arg[i]);
		}
		else if (i == 2)
			stc->t_die = ft_atoi(arg[i]);
		else if (i == 3)
			stc->t_eat = ft_atoi(arg[i]);
		else if (i == 4)
			stc->t_sleep = ft_atoi(arg[i]);
		else if (i == 5)
			stc->nbr_meals = ft_atoi(arg[i]);
		i++;
	}
	return (0);
}
