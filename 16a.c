/*
============================================================================
Name : 16a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to perform mandatory locking.
a. Implement write 

output : Writer Side : I am waiting...
                        Writer is inside the critical section. Press Enter to release the lock...

        Reader Side : Reader is Waiting.
                        Reader waiting...


============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void apply_write_lock(int fd) {
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("I am waiting...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Write lock failed");
        exit(EXIT_FAILURE);
    }
}

void release_write_lock(int fd) {
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Unlock failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd = open("testfile.txt", O_RDWR | O_CREAT, 0666);
    apply_write_lock(fd);
    printf("Writer is inside the critical section. Press Enter to release the lock...\n");

    getchar();

    printf("I am done.\n");
    release_write_lock(fd);

    close(fd);
    return 0;
}

