/*
============================================================================
Name : 1c.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : create myfifo using both shell command and script.

Output :-rw-rw-r-- 1 prabhav49 prabhav49    0 Aug  8 09:00 hardlnk_demo
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *fifo_name = "myfifo";
    int result = mknod(fifo_name, S_IFIFO | 0666, 0);

    if (result == 0) {
        printf("FIFO '%s' created successfully.\n", fifo_name);
    } else {
        perror("Error creating FIFO");
    }

    return 0;
}
