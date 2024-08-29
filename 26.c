/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement :Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"./a.out", "John", NULL};  // Arguments to be passed to the executable

    printf("Executing ./a.out with argument: John\n");
    execvp(args[0], args);

    printf("Failed to execute ./a.out\n");

    return 0;
}
