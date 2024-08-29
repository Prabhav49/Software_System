/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : excelv
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", "-Rl", NULL};  // Arguments array

    printf("Executing 'ls -Rl' using execv...\n");
    execv(args[0], args);
    printf("Failed to execute 'ls -Rl' using execv.\n");
    return 0;
}
