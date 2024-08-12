/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement :Write a program to copy file1 into file2 ($cp file1 file2). 
*/
#include <fcntl.h>   
#include <unistd.h>  
#include <stdio.h>   
#include <stdlib.h>  

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int sourceFd = open(argv[1], O_RDONLY);
    if (sourceFd == -1) {
        perror("Error opening source file");
        return 1;
    }

    int destFd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0744);
    if (destFd == -1) {
        perror("Error opening destination file");
        close(sourceFd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(sourceFd, buffer, BUFFER_SIZE)) > 0) {
        if (write(destFd, buffer, bytesRead) == -1) {
            perror("Error writing to destination file");
            close(sourceFd);
            close(destFd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
    }

    close(sourceFd);
    close(destFd);
    return 0;
}
