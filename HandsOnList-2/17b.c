/*
============================================================================
Name : 17b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to execute ls -l | wc.
            a. use dup2

output : 
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipefds[2];
    pid_t pid;
    pipe(pipefds);
    pid = fork();


    if (pid == 0) {
        close(pipefds[1]);
        dup2(pipefds[0], STDIN_FILENO); 
        close(pipefds[0]);

        execlp("wc", "wc", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        close(pipefds[0]);
        dup2(pipefds[1], STDOUT_FILENO);
        close(pipefds[1]);

        execlp("ls", "ls", "-l", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
