#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

struct thread_data {
	pthread_t thread_id;
	int thread_number;
};

/**
 * This is the thread function that expects a pointer to a struct thread_data.
 * The struct member thread_number should be the thread number (e.g. 1 for the 
 * first generated thrad, 2 for the second thread, ...)
 */
void* print_random_numbers(void* data)
{
	struct thread_data* td = (struct thread_data*)data;
	int r = rand();
	printf("Thread number %d: my first random number is: %d\n", td->thread_number, r);
	r = rand();
	printf("Thread number %d: my second random number is: %d\n", td->thread_number, r);
	r = rand();
	printf("Thredad number %d: my third random number is: %d\n", td->thread_number, r);
	return (void*)NULL;
}



int main(int argc, char** argv)
{


	srand(time(NULL));

	if (argc != 2){
		fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
		exit(-1);
	}
	int threads = atoi(argv[1]);
		
	printf("Main thread: Starting %d threads to calculate many different random numbers!\n", threads);

	// create a thead_data struct for every thread that we need
	struct thread_data* td = malloc(sizeof(struct thread_data) * threads);
	if (!td){
		perror("Error allocating thread data");
		exit(1);
	}

    

    for (int i = 0; i < threads; i++) {
        pthread_create(&((td + i)->thread_id), NULL, &print_random_numbers, (void*)&td[i]);
        pthread_join(td[i].thread_id, NULL);
    }

	// TODO: Insert your code here 
	
	free(td);

}