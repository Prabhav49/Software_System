/*
============================================================================
Name : 8a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a separate program using signal system call to catch the following signals.
            a. SIGSEGV
output :Caught SIGSEGV (Segmentation Fault)
        This is because I have made a invalid memory reference

============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV (Segmentation Fault)\n");
    printf("This is because I have made a invalid memory reference\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handle_sigsegv);

    int *p = NULL;
    *p = 42;

    return 0;
}