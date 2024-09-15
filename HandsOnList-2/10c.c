/*
============================================================================
Name : 10c.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using sigaction system call to catch the following signals.
                c. SIGFPE
output : aught signal SIGFPE (Floating-point exception).
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGFPE
void handle_sigfpe(int sig) {
    printf("Caught signal SIGFPE (Floating-point exception).\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;

    // Set up SIGFPE handler
    sa.sa_handler = handle_sigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    int x = 1 / 0; // Divide by zero to cause floating-point exception

    return 0;
}
