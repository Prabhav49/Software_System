/*
============================================================================
Name : 19e.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Create fifo using mkfifo library function

output : FIFO 'myfifo2' created using mkfifo()
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    if (mkfifo("myfifo2", 0666) == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("FIFO 'myfifo2' created using mkfifo()\n");
    return 0;
}
