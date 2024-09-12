/*
============================================================================
Name : 8e.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using signal system call to catch the following signals.
            e. SSIGALRM (use setitimer system call)
output :Caught SIGALRM (Alarm clock)

============================================================================
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM (Alarm clock)\n");
    exit(0);
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, handle_sigalrm);

    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    while (1) {
        pause();
    }

    return 0;
}
