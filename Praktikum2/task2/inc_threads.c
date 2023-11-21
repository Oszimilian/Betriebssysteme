#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

volatile int x = 0;
pthread_mutex_t mutex;


#define NUM_ITERATIONS 100000000
#define NUM_THREADS 2

#define ON 1
#define OFF 0
#define FAST 2
#define MUTEX_SWITCH OFF

void* thread_func(void *data)
{
#if MUTEX_SWITCH == FAST
	if(pthread_mutex_lock(&mutex) != 0) {
		perror("mutex_lock");
		exit(2);
	}
#endif

	for (int i = 0; i < NUM_ITERATIONS; ++i) {

#if MUTEX_SWITCH == ON
		if(pthread_mutex_lock(&mutex) != 0) {
			perror("mutex_lock");
			exit(2);
		}
#endif
		x++;
	
#if MUTEX_SWITCH == FAST
		if(pthread_mutex_unlock(&mutex) != 0) {
			perror("mutex_unlock");
			exit(2);
		}
#endif
	}

#if MUTEX_SWITCH == ON
		if(pthread_mutex_unlock(&mutex) != 0) {
			perror("mutex_unlock");
			exit(2);
		}
#endif

	return NULL;
}


int main (int argc, char** argv) {
	pthread_t threads[NUM_THREADS];
	int err;

	pthread_mutex_init(&mutex, NULL);


	for (int i = 0; i < NUM_THREADS; ++i) {

		if (-1 == (err = pthread_create(&threads[i], NULL, thread_func, NULL))) {
			fprintf(stderr, "Error creating thread: %s\n", strerror(err));
			exit(1);
		}
	}


	for (int i = 0; i < NUM_THREADS; ++i) {
		pthread_join(threads[i], NULL);
	}


	pthread_mutex_destroy(&mutex);

	/* Print the final value of 'x' */
	printf("Value of x after %i iterations by %i threads: %i\n", NUM_ITERATIONS, NUM_THREADS, x);


	return 0;
}
