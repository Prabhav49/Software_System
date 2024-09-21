/*
============================================================================
Name : 31b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to create a semaphore and initialize value to the semaphore.
            b. create a counting semaphore

output : Counting semaphore created and initialized to 3.
        Counting semaphore unlinked.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h> 
#include <unistd.h>

int main() {
    sem_t *sem;
    
    sem = sem_open("/counting_sem", O_CREAT, 0644, 3); 
    printf("Counting semaphore created and initialized to 3.\n");
    if (sem_close(sem) == -1) {
        perror("sem_close");
        exit(1);
    }

    if (sem_unlink("/counting_sem") == -1) {
        perror("sem_unlink");
        exit(1);
    }

    printf("Counting semaphore unlinked.\n");

    return 0;
}
