/*
============================================================================
Name : 12.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : rite a program to find out the opening mode of a file. Use fcntl.
output :/a.out 17_example.txt 
        File opening mode:
        - Read only

============================================================================
*/

#include <fcntl.h>  
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void print_file_mode(int flags) {
    printf("File opening mode:\n");
    if ((flags & O_ACCMODE) == O_RDONLY) {
        printf("  - Read only\n");
    }
    if ((flags & O_ACCMODE) == O_WRONLY) {
        printf("  - Write only\n");
    }
    if ((flags & O_ACCMODE) == O_RDWR) {
        printf("  - Read and write\n");
    }
    if (flags & O_APPEND) {
        printf("  - Append\n");
    }
    if (flags & O_CREAT) {
        printf("  - Create file if it does not exist\n");
    }
    if (flags & O_TRUNC) {
        printf("  - Truncate file to zero length\n");
    }
    if (flags & O_EXCL) {
        printf("  - Exclusive use (with O_CREAT)\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd;
    int flags;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    print_file_mode(flags);
    close(fd);

    return 0;
}
