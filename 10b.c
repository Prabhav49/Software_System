/*
============================================================================
Name : 10b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
b. open the file with od and check the empty spaces in between the data.

output : 0000000   P   r   a   b   h   a   v   P   a   n  \0  \0  \0  \0  \0  \0
        0000020  \0  \0  \0  \0   d   e   y   4   9   S   m   i   t   h
        0000036

============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char data1[] = "PrabhavPan";
    char data2[] = "dey49Smith"; 

    fd = open("10b_example.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    write(fd, data1, sizeof(data1) - 1);
    lseek(fd, 10, SEEK_CUR);
    write(fd, data2, sizeof(data2) - 1);
    close(fd);
    printf("Data written successfully.\n");

    return 0;
}
