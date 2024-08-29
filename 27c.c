/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : excele
Output :

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *envp[] = { NULL }; // Pass default environment or custom environment

    printf("Executing 'ls -Rl' using execle...\n");
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    printf("Failed to execute 'ls -Rl' using execle.\n");
    return 0;
}

