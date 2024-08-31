/*
============================================================================
Name : 26.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)


======================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    execl("./a.out", "./a.out", NULL);
    printf("Some error occured");
    return 0;
}