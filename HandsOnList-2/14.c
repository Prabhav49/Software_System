/*
============================================================================
Name : 14.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a simple program to create a pipe, write to the pipe, read from pipe and display on
            the monitor.

output : Parent process is writing to pipe: Hello from parent process
        Child process read from pipe: Hello from parent process

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int pipefds[2]; 
    pid_t pid;
    char write_msg[] = "Hello from parent process";
    char read_msg[100];

    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {

        close(pipefds[0]);
        printf("Parent process is writing to pipe: %s\n", write_msg);
        write(pipefds[1], write_msg, strlen(write_msg) + 1);
        close(pipefds[1]); 
    } else {

        close(pipefds[1]); 
        read(pipefds[0], read_msg, sizeof(read_msg));
        printf("Child process read from pipe: %s\n", read_msg);
        close(pipefds[0]); 
    }

    return 0;
}
