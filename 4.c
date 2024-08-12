/*
Name : Prabhav Pandey
Enroll :MT2024115
Problem Statement : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/

#include <fcntl.h>  
#include <stdio.h>  
#include <unistd.h> 

int main() {
    const char *filename = "2ndProg.txt";

    
    int fd = open(filename, O_RDWR);

    if (fd == -1) {
        perror("Error opening file in read/write mode");
        return 1;
    }

    printf("File '%s' opened successfully with file descriptor: %d\n", filename, fd);

    int fd_excl = open(filename, O_RDWR | O_EXCL);

    if (fd_excl == -1) {
        perror("Error opening file with O_EXCL");
    } else {
        printf("File '%s' opened with O_EXCL with file descriptor: %d\n", filename, fd_excl);
        close(fd_excl); 
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}
