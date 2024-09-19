/*
============================================================================
Name : 29.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description :Write a program to remove the message queue.

output : Message queue with ID 6 has been removed.

============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

// Define a structure for the message (not actually used for removal)
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;

    key = ftok("29file", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgctl(msgid, IPC_RMID, NULL);

    printf("Message queue with ID %d has been removed.\n", msgid);

    return 0;
}
