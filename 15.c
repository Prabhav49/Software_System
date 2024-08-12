/*
Name : Prabhav Pandey
Enroll : mt2024115
Problem Statement : Write a program to display the environmental variable of the user (use environ).
*/

#include <stdio.h>

// extern char **environ declares that the variable is defined elsewhere
extern char **environ;

int main() {
    int i = 0;
    char **env = environ;  // Access the global environment variable array

    printf("Environment Variables:\n");

   
    while (env[i] != NULL) {
        printf("%s\n", env[i]);
        i++;
    }

    return 0;
}

