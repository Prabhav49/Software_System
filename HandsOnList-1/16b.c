/*
============================================================================
Name : 16b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to perform mandatory locking.
b. Implement read lock

output :  Reader Side : Reader is Waiting.
                        Reader waiting...
                        Reader inside the critical section

        Writer Side : I am waiting...                                   
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void apply_read_lock(int fd) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid(); 

    printf("Reader waiting...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Read lock failed");
        exit(EXIT_FAILURE);
    }
}

void release_read_lock(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid(); 

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Unlock failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Open the file
    int fd = open("testfile.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Open failed");
        return EXIT_FAILURE;
    }

    printf("Reader is Waiting.\n");
    apply_read_lock(fd);
    printf("Reader inside the critical section.\n");

    getchar();
    printf("I am out of the Critical Section...\n");
    release_read_lock(fd);
    close(fd);

    return 0;
}

