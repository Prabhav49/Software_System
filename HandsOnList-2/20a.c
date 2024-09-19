/*
============================================================================
Name : 20a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

output : At 20a.c : 
        Enter a message to send: Hii I am Prabhav!!!
        Message sent to FIFO.

        At 20b.c
        Received message: Hii I am Prabhav!!!
============================================================================
*/

// writer.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo = "myfifo";

    mkfifo(fifo, 0666);

    int fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }


    char message[100];
    printf("Enter a message to send: ");
    fgets(message, 100, stdin);

    write(fd, message, strlen(message) + 1); 
    close(fd);

    printf("Message sent to FIFO.\n");
    return 0;
}

