/*
============================================================================
Name : 1b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
                10micro second
                a. ITIMER_VIRTUAL
output : ITIMER_VIRTUAL Timer expired!

============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("ITIMER_VIRTUAL Timer expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1);
    return 0;
}