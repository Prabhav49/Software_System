/*
Name  :Prabhav Pandey
Enroll : MT2024115
Problem Statement : excelp
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing 'ls -Rl' using execlp...\n");
    execlp("ls", "ls", "-Rl", NULL);
    printf("Failed to execute 'ls -Rl' using execlp.\n");
    return 0;
}
