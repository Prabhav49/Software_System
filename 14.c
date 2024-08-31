/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/

/*
============================================================================
Name : 14.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to find the type of a file.
            a. Input should be taken from command line.
            b. program should be able to identify any type of a file.

output : ./a.out sftlnk_demo 
            sftlnk_demo: symbolic link
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;

   
    if (lstat(argv[1], &file_stat) == -1) {
        perror("lstat");
        return 1;
    }

    if (S_ISREG(file_stat.st_mode)) {
        printf("%s: regular file\n", argv[1]);
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("%s: directory\n", argv[1]);
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("%s: character device\n", argv[1]);
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("%s: block device\n", argv[1]);
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("%s: FIFO/pipe\n", argv[1]);
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("%s: symbolic link\n", argv[1]);
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("%s: socket\n", argv[1]);
    } else {
        printf("%s: unknown file type\n", argv[1]);
    }
	
    return 0;
}
