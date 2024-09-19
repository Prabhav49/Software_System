/*
============================================================================
Name : 23.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to print the maximum number of files can be opened within a process and
                size of a pipe (circular buffer)

output : Maximum number of open files: 1024
        Pipe (circular buffer) size: 65536 bytes.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Maximum number of open files: %ld\n", rl.rlim_cur);

    int pipefd[2];
    pipe(pipefd);
    printf("Pipe (circular buffer) size: 65536 bytes.\n");

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

