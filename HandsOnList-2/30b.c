/*
============================================================================
Name : 30b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to create a shared memory.
            b. attach with O_RDONLY and check whether you are able to overwrite.

output : Data in shared memory: This is some data written to shared memory.
        Attempting to overwrite...
        Segmentation fault (core dumped)

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <string.h>

#define SHM_SIZE 1024  
int main() {
    key_t key;
    int shmid;
    char *data;

    key = ftok("30afile", 65);
    shmid = shmget(key, SHM_SIZE, 0444);
    
    data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Data in shared memory: %s\n", data);
    printf("Attempting to overwrite...\n");

    strcpy(data, "New data"); 

    printf("Data after overwrite attempt: %s\n", data);

    return 0;
}
