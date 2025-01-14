#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("First child with Process ID: %d\n", getpid());
    }
    else {
        printf("Parent after first fork PID: %d\n", getpid());
	wait(NULL);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("Second child with Process ID: %d\n", getpid());
    }
    else {
        printf("Parent after second fork PID: %d\n", getpid());
	wait(NULL);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("Third child with Process ID: %d\n", getpid());
    }
    else {
        printf("Parent after third fork PID: %d\n", getpid());
	wait(NULL);
    }
}
