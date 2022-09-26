/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:13:58 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/26 16:34:14 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_now_time_on_ms(struct timeval tv)
{
	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000 );
}

int		get_time_consumed(t_philo *trd)
{
	gettimeofday(&trd->tprm->tv, NULL);
	return (trd->tprm->tv.tv_sec * 1000 + trd->tprm->tv.tv_usec / 1000 - trd->tprm->start_time);
}


void	insialise_forks(t_param *ph_stc)
{
	int	i;

	i = 0;
	ph_stc->fork = malloc(sizeof(pthread_mutex_t) * ph_stc->all_nbr_philo);
	pthread_mutex_init(&ph_stc->lock, NULL);
	ph_stc->end_programme = 0;
	while (i < ph_stc->all_nbr_philo)
	{
		pthread_mutex_init(&ph_stc->fork[i], NULL);
		ph_stc->db_philo[i].r_fork = i;
		ph_stc->db_philo[i].l_fork = ((i + 1) % ph_stc->all_nbr_philo);
		i++;
	}
	ph_stc->start_time = get_now_time_on_ms(ph_stc->tv);
}

int check_arg(char **arg, t_param *stc)
{
	int	i;
	int	nbr;

	i = 1;
	while (arg[i])
	{
		nbr = ft_atoi(arg[i]);
		if (nbr < 0)
			return (1);
		if (i == 1)
		{
			stc->all_nbr_philo = nbr;
			stc->nbr_mutex = nbr;
			stc->nbr_fork = nbr;
		}
		else if (i == 2)
			stc->t_die = nbr;
		else if (i == 3)
			stc->t_eat = nbr;
		else if (i == 4)
			stc->t_sleep = nbr;
		else if (i == 5)
			stc->nbr_db_eat = nbr;
		i++;
	}
	return (0);
}
