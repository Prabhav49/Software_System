/*
============================================================================
Name : 1c.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
                10micro second
                a. ITIMER_PROF
output : ITIMER_PROF Timer expired!

============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("ITIMER_PROF Timer expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1);
    return 0;
}