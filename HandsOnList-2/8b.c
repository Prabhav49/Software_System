/*
============================================================================
Name : 8b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using signal system call to catch the following signals.
            b. SIGINT
output :Press Ctrl+C to trigger SIGINT...
        ^CCaught SIGINT (Interrupt from keyboard)

============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT (Interrupt from keyboard)\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1);
    return 0;
}
