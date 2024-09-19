/*
============================================================================
Name : 24.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to create a message queue and print the key and message queue id.

output : Message queue key: 1090522021
            Message queue ID: 1
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;
    FILE *fp = fopen("24file", "w");
    
    fclose(fp);
    key = ftok("progfile", 65); 
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Message queue key: %d\n", key);
    printf("Message queue ID: %d\n", msgid);
    
    return 0;
}
