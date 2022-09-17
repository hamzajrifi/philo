#include "philo.h"

int main(int ac, char **arg)
{
	if (ac < 4 || ac > 5 || check_arg(arg))	
		printf("Error\n");
	philo();
	return (0);
}
