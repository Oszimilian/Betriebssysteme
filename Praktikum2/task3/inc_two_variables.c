#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>


volatile int x = 0, y = 0;
pthread_mutex_t x_mutex, y_mutex;


#define NUM_ITERATIONS 1000000


void* thread_func_0(void *data)
{
	for (int i = 0; i < NUM_ITERATIONS; ++i) {
		pthread_mutex_lock(&x_mutex);
		//pthread_mutex_lock(&y_mutex);
		x++;
		y += 2;
		pthread_mutex_unlock(&x_mutex);
		//pthread_mutex_unlock(&y_mutex);
	}
	return NULL;
}


void* thread_func_1 (void *data) {
	for (int i = 0; i < NUM_ITERATIONS; ++i) {
		pthread_mutex_lock(&x_mutex);
		//pthread_mutex_lock(&y_mutex);
		x++;
		y += 2;
		pthread_mutex_unlock(&x_mutex);
		//pthread_mutex_unlock(&y_mutex);
	}
	return NULL;
}


int main(int argc, char** argv)
{
	pthread_t threads[2];
	int err;

	pthread_mutex_init(&x_mutex, NULL);
	pthread_mutex_init(&y_mutex, NULL);

	/* Create threads */
	if ((err = pthread_create(&threads[0], NULL, thread_func_0, NULL)) != 0) {
		fprintf(stderr, "Error creating thread #0: %s\n", strerror(err));
		exit(1);
	}
	if ((err = pthread_create(&threads[1], NULL, thread_func_1, NULL)) != 0) {
		fprintf(stderr, "Error creating thread #1: %s\n", strerror(err));
		exit (2);
	}

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	pthread_mutex_destroy(&x_mutex);
	pthread_mutex_destroy(&y_mutex);

	printf("x = %i, y = %i\n", x, y);

	return 0;
}
