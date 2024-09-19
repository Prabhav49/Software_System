/*
============================================================================
Name : 20b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

output : FIFO 'myfifo2' created using mkfifo()
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo = "myfifo";

    int fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);
    close(fd);

    return 0;
}
