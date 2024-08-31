/*
============================================================================
Name : 21.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program, call fork and print the parent and child process id.

Output :Parent process: PID = 5385, Child PID = 5386
	Child process: PID = 5386, Parent PID = 5385

======================================
*/



#include <stdio.h>
#include <unistd.h>

int main() { 
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    if (pid == 0) {
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }
    return 0;
}
