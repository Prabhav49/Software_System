/*
============================================================================
Name : 8g.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using signal system call to catch the following signals.
            g. SIGPROF (use setitimer system call)
output :Caught SIGPROF (Profiling timer expired)

============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigprof(int sig) {
    printf("Caught SIGPROF (Profiling timer expired)\n");
    exit(0);
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handle_sigprof);

    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);
    while (1) {
        pause(); 
    }

    return 0;
}
