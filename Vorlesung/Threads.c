
/*
 * 	gcc -pthread Threads.c
 */
 
#include <stdio.h>
#include <pthread.h>

void* func(void* data) {
	printf("func: %s \n", (char*)data);
	return NULL;
}

int main(int argc, char** argv) {
	pthread_t thread_id;
	
	printf("Main Thread: Starte Thread \n");
	
	char* s = "hallo welt";
	
	int status = pthread_create(&thread_id, NULL, &func, (void*)s);
	
	if(status == -1) {
		fprintf(stderr, "Error: Cant create Thread \n");
	}
	
	printf("Main Thread: Start child thread \n");
	pthread_join(thread_id, NULL);
	printf("Main Thread: Thread finished \n");
 
	return 0;
}
