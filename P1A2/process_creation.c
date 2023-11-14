#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void print_random_numbers(int child_number)
{
    int r = rand();
    printf("Child number %d: My PID is %d - my first random number is: %d\n", child_number, getpid(), r);
    r = rand();
    printf("Child number %d: My PID is %d - my second random number is: %d\n", child_number, getpid(), r);
    r = rand();
    printf("Child number %d: My PID is %d - my third random number is: %d\n", child_number, getpid(), r);
}

int main(int argc, char** argv)
{
    srand(time(NULL));

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_children>\n", argv[0]);
        exit(-1);
    }
    int children = atoi(argv[1]);

    pid_t* pids = (pid_t*)malloc(sizeof(pid_t) * children);
    if (!pids) {
        fprintf(stderr, "Error: can't allocate memory for child processes \n");
        return EXIT_FAILURE;
    }

    int status;
    for (int i = 0; i < children; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            printf("Child: %d \n", i);
            print_random_numbers(i);
            exit(0); 
        }
        if (pids[i] > 0) {
            waitpid(pids[i], &status, 0);
        }
    }

    // TODO: Insert your code here

    printf("\n\nFinished. Press Enter to quit the program.");
    getchar();
    free(pids); // Don't forget to free the allocated memory
}