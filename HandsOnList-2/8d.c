/*
============================================================================
Name : 8d.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using signal system call to catch the following signals.
            d. SIGALRM
output :Caught SIGALRM (Alarm clock)

============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM (Alarm clock)\n");
    exit(0);
}

int main() {
    signal(SIGALRM, handle_sigalrm);
    alarm(5);
    while (1) {
        pause();
    }

    return 0;
}
