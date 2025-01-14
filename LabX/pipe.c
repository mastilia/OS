#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main() {
    int p[2];
    pid_t pid;

    // Create pipe
    if (pipe(p) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        close(p[1]); // Close write end of pipe

        char buffer[32];
        read(p[0], buffer, sizeof(buffer)); // Read from pipe

        printf("Child receives message: %s\n", buffer);

        close(p[0]);
    }
    else {
        close(p[0]); // Close read end

        const char *message = "Hello World!";
	printf("Parent sends message: %s\n", message);
        write(p[1], message, strlen(message) + 1); // Write to pipe

        close(p[1]);

        // Wait for child
        wait(NULL);
    }
}
