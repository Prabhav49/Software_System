/*
============================================================================
Name : 4.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.

Output :-   File '3rdProg.txt' opened with O_EXCL with file descriptor: 3
============================================================================
*/

#include <fcntl.h>  
#include <stdio.h>  
#include <unistd.h> 

int main() {
    const char *filename = "3rdProg.txt";
    int fd_excl = open(filename, O_RDWR | O_EXCL);

    if (fd_excl == -1) {
        perror("Error opening file with O_EXCL");
    } else {
        printf("File '%s' opened with O_EXCL with file descriptor: %d\n", filename, fd_excl);
        close(fd_excl); 
    }
    return 0;
}
