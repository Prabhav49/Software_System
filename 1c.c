/*
Name : Prabhav Pandey
Enroll. : MT2024115
Problem Statement : create myfifo using both shell command and script.
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
