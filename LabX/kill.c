#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
    printf("Child Process received signal: %d\n", sig);
    exit(0);
}


void main() {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("Child process started, PID: %d\n", getpid());
        signal(SIGUSR1, signal_handler);
        printf("Child process waiting for signal...\n");
        while (1) { // Wait for a signal
            printf("Waiting...\n");
            sleep(1);
        }
    }
    else {
        printf("Parent process, PID: %d\n", getpid());
        sleep(2); // Give child some time
        printf("Parent sending signal to child...\n");
        kill(pid, SIGUSR1);
        sleep(1); // Give child some time
        printf("Parent Process exiting.\n");
    }
}
