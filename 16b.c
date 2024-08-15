/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to perform mandatory locking.
b. Implement read lock
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

#define NUM_READERS 1  // Change this to 1 to create only one reader

void apply_read_lock(int fd) {
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_RDLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Reader waiting...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Read lock failed");
        exit(EXIT_FAILURE);
    }
}

void release_read_lock(int fd) {
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

void *reader(void *arg) {
    int fd = *(int *)arg;

    printf("Reader thread started.\n");
    apply_read_lock(fd);
    printf("Reader inside the critical section.\n");

    getchar();

    printf("Reader done.\n");
    release_read_lock(fd);

    return NULL;
}

int main() {
    int fd = open("testfile.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Open failed");
        return EXIT_FAILURE;
    }

    pthread_t thread;

 
    if (pthread_create(&thread, NULL, reader, &fd) != 0) {
        perror("Thread creation failed");
        close(fd);
        return EXIT_FAILURE;
    }


    pthread_join(thread, NULL);

    close(fd);
    return 0;
}
