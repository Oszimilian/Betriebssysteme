#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0) {
        printf("Das ist der Kind-Prozess! \n");
        sleep(1);
    } else if(pid > 0) {
        printf("Das ist der Eltern-Prozess! \n");
        printf("Eltern-Prozess wartet auf Kind-Prozess Fertigstellung... \n");
        waitpid(pid, &status, 0);
        printf("Kind-Prozess ist fertig \n");
    } else {
        perror("Error");
    }

    return EXIT_SUCCESS;
}
    