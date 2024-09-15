/*
============================================================================
Name : 11.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
            use sigaction system call.
output : SIGINT signal is now ignored. Press Ctrl+C, but it will be ignored.
            ^C^C^C^C^C^C^C
            ^C^C^C^C^C^C^CSIGINT signal action reset to default. Press Ctrl+C to trigger the default action.
            ^C
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT
void handle_sigint(int sig) {
    printf("Caught signal SIGINT (Interrupt from keyboard).\n");
}

int main() {
    struct sigaction sa, sa_default;

    sa.sa_handler = SIG_IGN;  // Ignore the SIGINT signal
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT signal is now ignored. Press Ctrl+C, but it will be ignored.\n");
    sleep(10); 

    // Reset SIGINT to default action
    sa_default.sa_handler = SIG_DFL;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    if (sigaction(SIGINT, &sa_default, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT signal action reset to default. Press Ctrl+C to trigger the default action.\n");
    while (1) {
        pause(); 
    }

    return 0;
}
