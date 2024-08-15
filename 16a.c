/*
Name : Prabhav Pandey
ENroll : MT2024115
Problem Statement : Write a program to perform mandatory locking.
a. Implement write 
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
    printf("I am inside the critical section. Press Enter to release the lock...\n");

    getchar();

    printf("I am done.\n");
    release_write_lock(fd);

    close(fd);
    return 0;
}

