#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    FILE *file = fopen("pids.txt", "w");
    pid_t pid;

    if (file == NULL) {
	perror("opening file");
	exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
	fprintf(file, "Child PID: %d\n", getpid());
    }
    else {
	fprintf(file, "Parent PID: %d\n", getpid());
    }

    if (fclose(file) != 0) {
	perror("closing file");
	exit(EXIT_FAILURE);
    }
}
