/*
============================================================================
Name : 17c.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to execute ls -l | wc.
            a. use fcntl

output : 
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    int pipefds[2];
    pid_t pid;
    pipe(pipefds);

    pid = fork();
    if (pid == 0) {
        close(pipefds[1]);  
       fcntl(pipefds[0], F_DUPFD, STDIN_FILENO);
        close(pipefds[0]);

        execlp("wc", "wc", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        close(pipefds[0]);
        fcntl(pipefds[1], F_DUPFD, STDOUT_FILENO);
        close(pipefds[1]);

        execlp("ls", "ls", "-l", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
