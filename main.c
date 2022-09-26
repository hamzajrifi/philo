/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:07 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/26 21:59:48 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_checker(t_param *trd)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < trd->all_nbr_philo)
		{
			if (get_now_time_on_ms(trd->tv) - trd->db_philo[i].end_tm > trd->t_die)
			{
				printf("[%d ms] philo [%d] died \n", get_time_consumed(&trd->db_philo[i]), trd->db_philo[i].nbr_philo);
				exit(0);
			}
			// usleep(100);
			i++;
		}
		
	}
}

void	creat_philo_threads(t_param *trd)
{
	int		i;
	int		n_philo;

	i = 0;
	n_philo = trd->all_nbr_philo;
	trd->db_philo = malloc(sizeof(t_philo) * n_philo);
	trd->i = 0;
	insialise_forks(trd);
	while (n_philo > i)
	{
		trd->db_philo[i].nbr_philo = i;
		trd->db_philo[i].tprm = trd;
		trd->db_philo[i].index= 0;
		trd->db_philo[i].end_tm = get_now_time_on_ms(trd->tv);// 0 // 1
		pthread_create(&trd->db_philo[i].t_thread, NULL, philo, &trd->db_philo[i]);
		usleep(50);
		i++;
	}
	philo_checker(trd);
	i = 0;
	
	// while (n_philo > i)
	// {
		// pthread_join(trd->db_philo[i].t_thread, NULL);
		// i++;
	// }
}

int main(int ac, char **arg)
{
	t_param stc;

	if (ac < 5 || ac > 6 || check_arg(arg, &stc))	
		printf("Error\n");
	else
		creat_philo_threads(&stc);
	return (0);
}
