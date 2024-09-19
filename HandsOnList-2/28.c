/*
============================================================================
Name : 28.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)

output : Current permissions: 666
        Updated permissions: 642

============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;
    key = ftok("28file", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);
    msgctl(msgid, IPC_STAT, &buf);
    printf("Current permissions: %o\n", buf.msg_perm.mode & 0777);

    buf.msg_perm.mode = 0642;

    msgctl(msgid, IPC_SET, &buf);
    msgctl(msgid, IPC_STAT, &buf);

    printf("Updated permissions: %o\n", buf.msg_perm.mode & 0777);

    return 0;
}

