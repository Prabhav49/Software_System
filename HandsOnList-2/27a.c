/*
============================================================================
Name : 27a.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to receive messages from the message queue.
            a. with 0 as a flag
            b. with IPC_NOWAIT as a flag

output : Enter message to send: Hii Prabhav Here!!
        Message sent to the queue: Hii Prabhav Here!!
        
        Receiving message in blocking mode...
        Received message: Hii Prabhav Here!!

============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    ssize_t msg_len;

    key = ftok("27file", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    printf("Receiving message in blocking mode...\n");
    msg_len = msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
    if (msg_len == -1) {
        perror("msgrcv (blocking)");
        exit(EXIT_FAILURE);
    }
    printf("Received message: %s\n", message.msg_text);

    return 0;
}
