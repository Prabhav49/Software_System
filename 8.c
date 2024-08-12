/*
Name :Prabhav Pandey
Enrol : MT2024115
Problem Statement : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    
    file = fopen("8example.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    
    if (ferror(file)) {
        perror("Error reading from file");
    }

    
    fclose(file);

    return 0;
}
