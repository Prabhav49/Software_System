/*
============================================================================
Name : 22.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
                system call with FIFO

output : Waiting for data to be written to the FIFO within 10 seconds...
Received data: Hello, FIFO!
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/my_fifo"
#define TIMEOUT 10 

int main() {
    mkfifo(FIFO_PATH, 0666);
    int fifo_fd = open(FIFO_PATH, O_RDONLY | O_NONBLOCK);

    fd_set readfds;
    struct timeval tv;
    int retval;
    char buffer[1024];

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(fifo_fd, &readfds);

    printf("Waiting for data to be written to the FIFO within %d seconds...\n", TIMEOUT);
    retval = select(fifo_fd + 1, &readfds, NULL, NULL, &tv);

    if (retval == 0) {
        printf("Timeout! No data written within %d seconds.\n", TIMEOUT);
    } else {
        if (FD_ISSET(fifo_fd, &readfds)) {
            ssize_t bytes_read = read(fifo_fd, buffer, sizeof(buffer) - 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0'; 
                printf("Received data: %s\n", buffer);
            } else {
                printf("No data to read.\n");
            }
        }
    }

    close(fifo_fd);
    return 0;
}
