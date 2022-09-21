#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

struct t_list
{
	int				*nbr;
	pthread_t		thread_id;
	pthread_mutex_t	lock;
};

void *myturn(void *arg)
{
	
	for (size_t i = 0; i < 20; i++)
	{
		sleep(1);
		// pthread_mutex_lock();
		printf("My Turn ptr =  \n");

		// pthread_mutex_unlock();
	}
	return NULL;
}

void *yourturn()
{
	for (int i = 1; i < 4; i++)
	{
		sleep(1);
		printf("Your Turn \n");
	}
	return NULL;
}
int main()
{
	struct t_list lst;

	pthread_create(&lst.thread_id, NULL, myturn, NULL);
	// myturn(lst.nbr);
	yourturn();
	pthread_join(lst.thread_id, (void *)&lst.nbr);
	printf("end Thread && nbr =\n");
	exit(0);
}
