#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 3

void* thread_func(void* data) {
    printf("Thread: %s \n", (char*)data);
    return NULL;
}

int main(void) {

    pthread_t thread[THREAD_COUNT];
    int status[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        char c[50];
        sprintf(c, "Maximilian: %d", i);
        status[i] = pthread_create(&thread[i], NULL, &thread_func, (void*)c);
        if(status[i] == -1) {
            fprintf(stderr, "Error with thread: %d \n", i);
            exit(EXIT_FAILURE);
        }

        pthread_join(thread[i], NULL);
    }


        


    return EXIT_SUCCESS;
}
