/*
============================================================================
Name : 18.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to find out total number of directories on the pwd.
                execute ls -l | grep ^d | wc ? Use only dup2.

output : 
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2]; 
    int pipe2[2]; 
    
    pipe(pipe1);
    if (fork() == 0) {
        close(pipe1[0]); 
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[1]);

        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    pipe(pipe2);

    if (fork() == 0) {

        close(pipe1[1]); 
        dup2(pipe1[0], STDIN_FILENO); 
        close(pipe1[0]); 

        close(pipe2[0]);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe2[1]); 

        execlp("grep", "grep", "^d", (char *)NULL); 
        perror("execlp grep");
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) {
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]); 
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe2[0]); 

        execlp("wc", "wc", "-l", (char *)NULL);
        perror("execlp wc");
        exit(EXIT_FAILURE);
    }


    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}
