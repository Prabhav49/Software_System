/*
============================================================================
Name : 21a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write two programs so that both can communicate by FIFO -Use two way communications.

output : FIFO 'myfifo2' created using mkfifo()
============================================================================
*/

// parent.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo1 = "fifo1"; 
    const char *fifo2 = "fifo2";

    char write_message[100], read_message[100];
    int write_fd = open(fifo1, O_WRONLY);
    int read_fd = open(fifo2, O_RDONLY);
    
    if (write_fd == -1 || read_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Parent: Enter message: ");
        fgets(write_message, 100, stdin);
        write(write_fd, write_message, strlen(write_message) + 1);

        read(read_fd, read_message, sizeof(read_message));
        printf("Parent received: %s", read_message);

        if (strncmp(write_message, "exit", 4) == 0 || strncmp(read_message, "exit", 4) == 0) {
            break;
        }
    }

    close(write_fd);
    close(read_fd);
    return 0;
}
