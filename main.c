/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:07 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/28 23:43:24 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_if_end(t_param *trd)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&trd->lock);
	while (i < trd->all_nbr_philo && trd->db_philo[i].nbr_meal_eat
		== trd->nbr_meals)
		i++;
	if (trd->nbr_meals && i == trd->all_nbr_philo)
	{
		pthread_mutex_unlock(&trd->lock);
		return (1);
	}
	pthread_mutex_unlock(&trd->lock);
	return (0);
}

void	philo_checker(t_param *trd)
{
	int	i;

	while (1337)
	{
		i = 0;
		while (i < trd->all_nbr_philo)
		{
			pthread_mutex_lock(&trd->lock);
			if (get_now_time_on_ms() - trd->db_philo[i].end_tm > trd->t_die)
			{
				pthread_mutex_lock(&trd->print);
				printf("[%d ms] philo [%d] died\n",
					get_now_time_on_ms() - trd->db_philo[i].end_tm,
					trd->db_philo[i].nbr_philo + 1);
				trd->end_programme = 1;
				pthread_mutex_unlock(&trd->lock);
				pthread_mutex_unlock(&trd->print);
				return ;
			}
			i++;
			pthread_mutex_unlock(&trd->lock);
		}
		if (check_if_end(trd))
			break ;
	}
}

void	creat_philo_threads(t_param *trd)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = trd->all_nbr_philo;
	trd->db_philo = malloc(sizeof(t_philo) * n_philo);
	trd->i = 0;
	insialise_forks(trd);
	while (n_philo > i)
	{
		trd->db_philo[i].nbr_philo = i;
		trd->db_philo[i].tprm = trd;
		trd->db_philo[i].end_tm = get_now_time_on_ms();
		if (pthread_create(&trd->db_philo[i].t_thread, NULL,
				philo, &trd->db_philo[i]))
			return ;
		usleep(50);
		i++;
	}
	philo_checker(trd);
	i = -1;
	while (trd->all_nbr_philo > 1 && n_philo > ++i)
		pthread_join(trd->db_philo[i].t_thread, NULL);
}

int	main(int ac, char **arg)
{
	t_param	stc;

	if (ac < 5 || ac > 6 || check_arg(arg, &stc))
		printf("Error\n");
	else
		creat_philo_threads(&stc);
	return (0);
}
