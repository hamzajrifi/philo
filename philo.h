/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:30 by hjrifi            #+#    #+#             */
/*   Updated: 2022/09/28 22:12:58 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

//==================== struct ========================
struct	s_param;

typedef struct s_philo
{
	pthread_t		t_thread;
	unsigned int	end_tm;
	int				index;
	int				r_fork;
	int				l_fork;
	int				nbr_meal_eat;
	int				nbr_philo;
	struct s_param	*tprm;
}t_philo;

typedef struct s_param
{
	struct timeval	tv;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	int				all_nbr_philo;
	int				nbr_mutex;
	int				nbr_fork;
	int				nbr_meals;
	int				x_meals;
	unsigned int	t_die;
	int				t_eat;
	int				t_sleep;
	int				i;
	int				tm_now;
	int				end_programme;
	unsigned int	start_time;
	t_philo			*db_philo;
}	t_param;

//=============  philo.c ===========================
void			*philo(void *arg);
void			my_print(t_philo *ph, char *str);

//=============  checker.c ===========================
int				check_arg(char **arg, t_param *stc);
void			insialise_forks(t_param *ph_stc);
int				get_time_consumed(t_philo *trd);
unsigned int	get_now_time_on_ms(void);

//=============  utils_function.c ===========================
int				ft_atoi(const char *str);
void			ft_sleep(t_philo *trd, unsigned int t_sleep);

#endif
