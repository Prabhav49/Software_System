/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(const char *path) {
    struct stat file_stat;


    if (stat(path, &file_stat) == -1) {
        perror("stat");
        return;
    }

   
    if (S_ISREG(file_stat.st_mode)) {
        printf("%s is a regular file.\n", path);
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("%s is a directory.\n", path);
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("%s is a symbolic link.\n", path);
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("%s is a character device.\n", path);
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("%s is a block device.\n", path);
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("%s is a FIFO (named pipe).\n", path);
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("%s is a socket.\n", path);
    } else {
        printf("%s is of unknown type.\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    print_file_type(argv[1]);
    return 0;
}

