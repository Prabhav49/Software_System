/*
============================================================================
Name : 10a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
output :Caught signal SIGSEGV (Segmentation fault).
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGSEGV
void handle_sigsegv(int sig) {
    printf("Caught signal SIGSEGV (Segmentation fault).\n");
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;

    // Set up SIGSEGV handler
    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    int *p = NULL; 
    *p = 0; 

    return 0;
}
