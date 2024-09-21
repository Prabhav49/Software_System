/*
============================================================================
Name : 31a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to create a semaphore and initialize value to the semaphore.
            a. create a binary semaphore

output : Binary semaphore created and initialized to 1.
        Binary semaphore unlinked.

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h> 
#include <unistd.h>

int main() {
    sem_t *sem;
    sem = sem_open("/binary_sem", O_CREAT, 0644, 1);
    printf("Binary semaphore created and initialized to 1.\n");

    if (sem_close(sem) == -1) {
        perror("sem_close");
        exit(1);
    }

    if (sem_unlink("/binary_sem") == -1) {
        perror("sem_unlink");
        exit(1);
    }

    printf("Binary semaphore unlinked.\n");

    return 0;
}
