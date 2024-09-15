/*
============================================================================
Name : 10b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using sigaction system call to catch the following signals.
                b. SIGINT
output : Waiting for SIGINT signal. Press Ctrl+C to trigger it.

        ^CCaught signal SIGINT (Interrupt from keyboard).

============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT
void handle_sigint(int sig) {
    printf("Caught signal SIGINT (Interrupt from keyboard).\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;

    // Set up SIGINT handler
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Wait for SIGINT signal
    printf("Waiting for SIGINT signal. Press Ctrl+C to trigger it.\n");
    while (1) {
        pause(); 
    }

    return 0;
}
