#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//==================== struct ========================

typedef struct s_philo
{
	pthread_t		t_thread;
	int				index;
	int				r_fork;
	int				l_fork;
	int				ph_time;
	int				nbr_philo;
	pthread_mutex_t	*m_fork;
}t_philo;

typedef struct s_param
{
	int		all_nbr_philo;
	int		nbr_mutex;
	int		nbr_fork;
	int		nbr_db_eat;
	int		nbr_meals;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		i;
	t_philo	*db_philo;
} t_param;

//=============  philo.c ===========================
void	*philo(void  *arg);

//=============  checker.c ===========================
int		check_arg(char **arg, t_param *stc);
void	insialise_forks(t_param *ph_stc);

//=============  utils_function.c ===========================
int     ft_atoi(const char *str);

#endif
