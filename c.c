#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// struct t_list
// {
// 	int				*nbr;
// 	pthread_t		thread_id;
// 	pthread_mutex_t	lock;
// };

// void *myturn(void *arg)
// {
	
// 	for (size_t i = 0; i < 20; i++)
// 	{
// 		sleep(1);
// 		// pthread_mutex_lock();
// 		printf("My Turn ptr =  \n");

// 		// pthread_mutex_unlock();
// 	}
// 	return NULL;
// }

// void *yourturn()
// {
// 	for (int i = 1; i < 4; i++)
// 	{
// 		sleep(1);
// 		printf("Your Turn \n");
// 	}
// 	return NULL;
// }
// int main()
// {
// 	struct t_list lst;

// 	pthread_create(&lst.thread_id, NULL, myturn, NULL);
// 	// myturn(lst.nbr);
// 	yourturn();
// 	pthread_join(lst.thread_id, (void *)&lst.nbr);
// 	printf("end Thread && nbr =\n");
// 	exit(0);
// }

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* trythis(void* arg)
{
	pthread_mutex_lock(&lock);

	unsigned long i = 0;
	counter += 1;
	printf("\n Job %d has started\n", counter);

	for (i = 0; i < (0xFFFFFFFF); i++)
		;

	printf("\n Job %d has finished\n", counter);

	pthread_mutex_unlock(&lock);

	return NULL;
}

int main(void)
{
	int i = 0;
	int error;

	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;
	}

	while (i < 2) {
		error = pthread_create(&(tid[i]),
							NULL,
							&trythis, NULL);
		if (error != 0)
			printf("\nThread can't be created :[%s]",
				strerror(error));
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}
