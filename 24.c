/*
============================================================================
Name : 24.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to create an orphan process.

Output :  Parent process (PID: 5143) is exiting...
	  Child process (PID: 5144) is now orphaned and adopted by init.
	  Child's parent PID after becoming orphan: 1667

======================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent process (PID: %d) is exiting...\n", getpid());
        exit(0);
   } else if (pid == 0) {
        sleep(5);
        printf("Child process (PID: %d) is now orphaned and adopted by init.\n", getpid());
        printf("Child's parent PID after becoming orphan: %d\n", getppid());
    } else {
        printf("Fork failed.\n");
        exit(1);
    }

    return 0;
}
