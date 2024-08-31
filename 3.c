/*
============================================================================
Name : 3.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call 

Output :-   File '3rdProg.txt' created successfully with file descriptor: 3
============================================================================
*/

#include <fcntl.h>  // For creat()
#include <stdio.h>  // For printf()
#include <unistd.h> // For close()

int main() {
    const char *filename = "3rdProg.txt";
    int fd = creat(filename, 0666);

    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

   
    printf("File '%s' created successfully with file descriptor: %d\n", filename, fd);

   
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}
