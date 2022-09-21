#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//==================== struct ========================
typedef struct s_philo
{
    int nbr_philo;
    int nbr_mutex;
    int nbr_fork;
    int nbr_db_eat;
    int nbr_meals;
    int t_die;
    int t_eat;
    int t_sleep;
    int index;
}t_philo;

typedef struct s_param
{
    pthread_t		*t_thread;
    pthread_mutex_t	*lock;
    t_philo         *t_philo;
    int             r_fork;
} t_param;

//=============  philo.c ===========================
void	*philo(void  *arg);

//=============  checker.c ===========================
int check_arg(char **arg, t_philo *stc);

//=============  utils_function.c ===========================
int     ft_atoi(const char *str);

#endif
