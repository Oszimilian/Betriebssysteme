
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define INPUT_LEN 50

int main(int argc, char** argv)
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <program> [args]\n", argv[0]);
		exit(1);
	}
	char* prog_name = argv[1];
	pid_t pid = fork();
	int status;

	if (pid == 0) {
		char c[INPUT_LEN];
		int len = 0;
		for (int i = 1; i < argc; i++) {
			len += strlen(argv[i]);
			if (len < INPUT_LEN) {
				strcat(c, argv[i]);
				strcat(c, " ");
			}
		}

		printf("Child: %s \n", c);
		system(c);

	} else if(pid > 0) {
		waitpid(pid, &status, 0);
	}

	return 0;

}
