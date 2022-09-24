/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:13:58 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/24 20:51:15 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_now_time_on_ms(t_philo *trd)
{
	int	time_ms;
	static int	start;

	start = trd->tprm->start_time;
	gettimeofday(&trd->tprm->tv, NULL);
	if(((trd->tprm->tv.tv_usec - trd->tprm->start_time) / 1000) < 0)
		trd->tprm->start_time = 0; // i have data race here .....
	return (trd->tprm->tv.tv_usec - trd->tprm->start_time) / 1000;
}

void	insialise_forks(t_param *ph_stc)
{
	int	i;

	i = 0;
	ph_stc->fork = malloc(sizeof(pthread_mutex_t) * ph_stc->all_nbr_philo);
	while (i < ph_stc->all_nbr_philo)
	{
		pthread_mutex_init(&ph_stc->fork[i], NULL);
		ph_stc->db_philo[i].r_fork = i;
		ph_stc->db_philo[i].l_fork = ((i + 1) % ph_stc->all_nbr_philo);
		i++;
	}
	gettimeofday(&ph_stc->tv, NULL);
	ph_stc->start_time = ph_stc->tv.tv_usec; 
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
