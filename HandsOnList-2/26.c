/*
============================================================================
Name : 26.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to send messages to the message queue. Check $ipcs -q

output : Enter message to send: Hello
        Message sent to the queue: Hello


        :: ipcs -q
        
                ------ Message Queues --------
        key        msqid      owner      perms      used-bytes   messages    
        0xffffffff 0          prabhav49  666        0            0           
        0x41000ba5 1          prabhav49  666        0            0           
        0x41000c96 2          prabhav49  666        0            0           
        0x41000c9a 3          prabhav49  666        600          6
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("26file", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    message.msg_type = 1; 
    printf("Enter message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    msgsnd(msgid, &message, sizeof(message.msg_text), 0);

    printf("Message sent to the queue: %s\n", message.msg_text);

    return 0;
}
