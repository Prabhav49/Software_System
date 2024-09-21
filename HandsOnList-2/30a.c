/*
============================================================================
Name : 30a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to create a shared memory.
            a. write some data to the shared memory

output : Message queue with ID 6 has been removed.

============================================================================
*/

// program_a.c: Create shared memory and write data

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024 

int main() {
    key_t key;
    int shmid;
    char *data;
    
    key = ftok("30afile", 65);

    shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT);
    data = (char *)shmat(shmid, NULL, 0);

    strcpy(data, "This is some data written to shared memory.");
    printf("Data written to shared memory: %s\n", data);
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
