/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
*/

#include <fcntl.h>   // For open()
#include <unistd.h>  // For lseek(), write(), close()
#include <stdio.h>   // For perror(), printf()
#include <stdlib.h>  // For exit()

#define FILE_NAME "example.txt"
#define BUFFER_SIZE 10

int main() {
    int fd;
    ssize_t result;
    off_t offset;

   
    char writeBuffer1[BUFFER_SIZE] = "HelloRahul";
    char writeBuffer2[BUFFER_SIZE] = "Bangalore";

   
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write 10 bytes to the file
    result = write(fd, writeBuffer1, BUFFER_SIZE);
    if (result == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("First write: %ld bytes written\n", (long)result);

    // Move the file pointer by 10 bytes
    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error seeking file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File pointer moved to offset: %ld\n", (long)offset);

    // Write another 10 bytes to the file
    result = write(fd, writeBuffer2, BUFFER_SIZE);
    if (result == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Second write: %ld bytes written\n", (long)result);

    // Close the file
    close(fd);

    return 0;
}
