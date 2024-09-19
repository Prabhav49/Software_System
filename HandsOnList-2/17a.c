/*
============================================================================
Name : 17a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to execute ls -l | wc.
            a. use dup

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
   pid=fork();

    if (pid == 0) {
        close(pipefds[1]); 
        dup(pipefds[0]);  
        close(pipefds[0]);

        execlp("wc", "wc", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        close(pipefds[0]); 
        dup(pipefds[1]);  
        close(pipefds[1]);

        execlp("ls", "ls", "-l", (char *) NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
