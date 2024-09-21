/*
============================================================================
Name : 30d.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to create a shared memory.
            c. remove the shared memory.

output : Shared memory removed.

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 
int main() {
    key_t key;
    int shmid;

    key = ftok("30afile", 65);

    shmid = shmget(key, SHM_SIZE, 0644);
    shmctl(shmid, IPC_RMID, NULL) ;

    printf("Shared memory removed.\n");

    return 0;
}
