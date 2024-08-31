/*
============================================================================
Name : 10a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek

output : First write: 10 bytes written
            File pointer moved to offset: 20
            Second write: 10 bytes written
            The  value of seek is : 20
============================================================================
*/

#include <fcntl.h>   
#include <stdio.h>   
#include <stdlib.h>  

#define FILE_NAME "example.txt"
#define BUFFER_SIZE 10

int main() {
    int fd;
    ssize_t result;
    off_t offset;

   
    char writeBuffer1[BUFFER_SIZE] = "HelloRahul";
    char writeBuffer2[BUFFER_SIZE] = "Bangalore";

   
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0666);

    result = write(fd, writeBuffer1, BUFFER_SIZE);

    printf("First write: %ld bytes written\n", (long)result);

   
    offset = lseek(fd, 10, SEEK_CUR);
    printf("File pointer moved to offset: %ld\n", (long)offset);

    result = write(fd, writeBuffer2, BUFFER_SIZE);
    printf("Second write: %ld bytes written\n", (long)result);
	printf("The  value of seek is : %d\n", offset);
    close(fd);

    return 0;
}
