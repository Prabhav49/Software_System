/*
Name :Prabhav Pandey
Enroll : MT2024115
Problem Statement : execvp
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};  // Arguments array

    printf("Executing 'ls -Rl' using execvp...\n");
    execvp(args[0], args);
    printf("Failed to execute 'ls -Rl' using execvp.\n");
    return 0;
}
