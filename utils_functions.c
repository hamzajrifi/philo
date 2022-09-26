/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:48 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/24 18:14:49 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	signe;
	long	rest;

	i = 0;
	signe = 1;
	rest = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		rest = rest * 10 + (str[i] - 48);
		if (rest < -2147483648 && signe == -1)
			return (0);
		if (rest > 2147483647 && signe == 1)
			return (-1);
		i++;
	}
	return (rest * signe);
}

void	ft_sleep(t_param *tprm, int t_sleep)
{
	int i;
	i = get_now_time_on_ms(tprm->tv);
	while (!tprm->end_programme && (get_now_time_on_ms(tprm->tv) - tprm->i < t_sleep))
		usleep(50);
}