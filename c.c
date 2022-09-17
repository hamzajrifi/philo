#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myturn(void *vargp)
{
	while (1)
	{
		sleep(1);
		printf("My Turn \n");
	}
	return NULL;
}

void *yourturn(void *vargp)
{
	while (1)
	{
		sleep(1);
		printf("Your Turn \n");
	}
	return NULL;
}
int main()
{
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	yourturn();
	// pthread_join(thread_id, NULL);
	printf("end Thread\n");
	exit(0);
}
