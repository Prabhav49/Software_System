// program2.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;

    printf("Enter the PID of Program 1: ");
    scanf("%d", &pid);

    if (kill(pid, SIGUSR1) == 0) {
        printf("SIGUSR1 sent successfully to process %d\n", pid);
    } else {
        perror("Failed to send signal");
        exit(EXIT_FAILURE);
    }
    /*
    if (kill(pid, SIGSTOP) == 0) {
        printf("SIGSTOP sent successfully to process %d\n", pid);
    } else {
        perror("Failed to send signal");
        exit(EXIT_FAILURE);
    }
    */

    return 0;
}
