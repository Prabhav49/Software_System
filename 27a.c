/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem tatement : a. execl
Output : 

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing 'ls -Rl' using execl...\n");
    execl("/bin/ls", "ls", "-Rl", NULL);
    printf("Failed to execute 'ls -Rl' using execl.\n");
    return 0;
}

