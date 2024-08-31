/*
Name :Prabhav Pandey 
Enroll : MT2024115
Problem Statemet : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/

/*
============================================================================
Name : 6.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

Output :-  HII PRABHAV PANDEY
HII PRABHAV PANDEY

============================================================================
*/

#include <unistd.h>  
#include <stdio.h>   

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Read from STDIN until end of input
    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
       
        if (write(STDOUT_FILENO, buffer, bytesRead) == -1) {
            perror("Error writing to STDOUT");
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }

    return 0;
}

