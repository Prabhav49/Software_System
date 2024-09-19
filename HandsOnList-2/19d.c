/*
============================================================================
Name : 19d.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Create fifo usinf mknod system call

output : FIFO 'myfifo' created using mknod()
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    if (mknod("myfifo", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        return 1;
    }
    printf("FIFO 'myfifo' created using mknod()\n");
    return 0;
}
