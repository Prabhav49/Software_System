/*
============================================================================
Name : 16.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to send and receive data from parent to child vice versa. Use two way
            communication.

output : Parent: Enter a message to send to the child: Hello I am your Parent!!
        Child received from parent: Hello I am your Parent!!
        Child: Enter a message to send to the parent: Hiii
        Parent received from child: Hiii
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int parent_to_child[2];  
    int child_to_parent[2];
    pid_t pid;
    char parent_msg[100];
    char child_msg[100];
    char read_buffer[100];

    if (pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(parent_to_child[0]);  
        close(child_to_parent[1]);

        printf("Parent: Enter a message to send to the child: ");
        fgets(parent_msg, sizeof(parent_msg), stdin);
        parent_msg[strcspn(parent_msg, "\n")] = 0; 

        write(parent_to_child[1], parent_msg, strlen(parent_msg) + 1);
        read(child_to_parent[0], read_buffer, sizeof(read_buffer));
        printf("Parent received from child: %s\n", read_buffer);
        close(parent_to_child[1]);
        close(child_to_parent[0]);
    } else {
        close(parent_to_child[1]); 
        close(child_to_parent[0]);

        read(parent_to_child[0], read_buffer, sizeof(read_buffer));
        printf("Child received from parent: %s\n", read_buffer);

        printf("Child: Enter a message to send to the parent: ");
        fgets(child_msg, sizeof(child_msg), stdin);
        child_msg[strcspn(child_msg, "\n")] = 0; 

        write(child_to_parent[1], child_msg, strlen(child_msg) + 1);

        close(parent_to_child[0]);
        close(child_to_parent[1]);
    }

    return 0;
}
