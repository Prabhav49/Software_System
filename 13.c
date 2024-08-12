/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
   
    fd_set readfds;
    
   
    FD_ZERO(&readfds);

   
    FD_SET(STDIN_FILENO, &readfds);

   
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");

   
    int retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select()");
        return 1;
    } else if (retval) {
        printf("Data is available now.\n");
       
    } else {
        printf("No data within 10 seconds.\n");
    }

    return 0;
}
