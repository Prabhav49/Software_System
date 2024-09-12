/*
============================================================================
Name : 9.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
                signal - Use signal system call.
output :SIGINT is now being ignored. Press Ctrl+C won't have any effect.
        ^CSIGINT has been reset to default action. Press Ctrl+C will now terminate the program.
        ^C
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void setup_signal_handlers() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now being ignored. Press Ctrl+C won't have any effect.\n");
    sleep(5);
    signal(SIGINT, SIG_DFL);
    printf("SIGINT has been reset to default action. Press Ctrl+C will now terminate the program.\n");
}

int main() {
    setup_signal_handlers();
    while (1) {
        pause(); 
    }

    return 0;
}
