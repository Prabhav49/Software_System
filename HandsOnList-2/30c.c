/*
============================================================================
Name : 30c.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to create a shared memory.
            c. detach the shared memory.

output : Data before detaching: This is some data written to shared memory.
        Shared memory detached.

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
    char *data;

    key = ftok("30afile", 65);
    shmid = shmget(key, SHM_SIZE, 0644);
    data = (char *)shmat(shmid, NULL, 0);

    printf("Data before detaching: %s\n", data);
    printf("Shared memory detached.\n");

    return 0;
}
