/*
============================================================================
Name : 12.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
            the parent process from the child process.

output : Child process sending SIGTERM to parent process (PID: 0).
            Parent process received SIGTERM signal.

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t parent_pid;

void handle_sigterm(int sig) {
    if (sig == SIGTERM) {
        printf("Parent process received SIGTERM signal.\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {

        sleep(1);
        printf("Child process sending SIGTERM to parent process (PID: %d).\n", parent_pid);
        kill(parent_pid, SIGTERM);

        exit(EXIT_SUCCESS);
    } else {
        parent_pid = getpid();

        struct sigaction sa;
        sa.sa_handler = handle_sigterm;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        if (sigaction(SIGTERM, &sa, NULL) == -1) {
            perror("sigaction");
            exit(EXIT_FAILURE);
        }
        wait(NULL);
        printf("Parent process is waiting for SIGTERM signal.\n");
        while (1) {
            pause(); 
        }
    }

    return 0;
}
