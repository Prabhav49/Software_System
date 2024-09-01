/*
============================================================================
Name : 22.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Output : (In 22_output.txt) Parent process writing to file
                            Child process writing to file
                            Parent process writing to file
                            Child process writing to file

======================================
*/



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    int fd = open("22_output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    if (pid == 0) {
        const char *child_msg = "Child process writing to file\n";
        write(fd, child_msg, sizeof("Child process writing to file\n") - 1);
    }

    else {
        const char *parent_msg = "Parent process writing to file\n";
        write(fd, parent_msg, sizeof("Parent process writing to file\n") - 1);
    }
    close(fd);
    
    return 0;
}
