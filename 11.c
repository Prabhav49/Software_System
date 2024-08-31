/*
============================================================================
Name : 11.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
output :Data from original FD
        Data from duplicated FD
        Data from duplicated FD
============================================================================
*/


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "11example.txt"
#define BUFFER_SIZE 20

void append_to_file(int fd, const char *message) {
    ssize_t bytesWritten;
    bytesWritten = write(fd, message, strlen(message));
}

int main() {
    int fd, fd_dup, fd_dup2;
    int result;
    const char *message1 = "Data from original FD\n";
    const char *message2 = "Data from duplicated FD\n";

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0666);
    fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("Error duplicating file descriptor using dup");
        close(fd);
        exit(EXIT_FAILURE);
    }

    fd_dup2 = dup2(fd, fd + 1); // fd + 1 to avoid overlap with original fd
    if (fd_dup2 == -1) {
        perror("Error duplicating file descriptor using dup2");
    }

    append_to_file(fd, message1);
    append_to_file(fd_dup, message2);
    append_to_file(fd_dup2, message2);

    close(fd);
    close(fd_dup);
    close(fd_dup2);

    return 0;
}

