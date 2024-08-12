/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/

#include <fcntl.h>   // For open()
#include <stdio.h>   // For printf(), perror()
#include <stdlib.h>  // For exit()
#include <unistd.h>  // For close(), sleep()

int main() {
    const char *filenames[5] = {
        "5file1.txt",
        "5file2.txt",
        "5file3.txt",
        "5file4.txt",
        "5file5.txt"
    };

    int fds[5];

    for (int i = 0; i < 5; i++) {
        fds[i] = open(filenames[i], O_CREAT | O_WRONLY, 0666);
        if (fds[i] == -1) {
            perror("Error creating file");
            exit(EXIT_FAILURE);
        }
        printf("File '%s' created with file descriptor: %d\n", filenames[i], fds[i]);
    }

    
    while (1) {
        sleep(5);
    }

   
    for (int i = 0; i < 5; i++) {
        close(fds[i]);
    }

    return 0;
}

