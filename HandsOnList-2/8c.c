/*
============================================================================
Name : 8c.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using signal system call to catch the following signals.
            c. SIGFPE
output :Caught SIGFPE (Floating-point exception)

============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig) {
    printf("Caught SIGFPE (Floating-point exception)\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handle_sigfpe);
    int x = 1 / 0;
    return 0;
}
