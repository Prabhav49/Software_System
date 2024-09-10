/*
============================================================================
Name : 28.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Output: Current policy:
        Current scheduling policy: SCHED_OTHER

        Policy changed to SCHED_FIFO with priority 10
        New policy:
        Current scheduling policy: SCHED_FIFO

        Policy changed to SCHED_RR with priority 10
        New policy:
        Current scheduling policy: SCHED_RR
======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Current scheduling policy: Unknown\n");
            break;
    }
}

int main() {
    int current_policy;
    struct sched_param param;

    current_policy = sched_getscheduler(0);

    if (current_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Current policy:\n");
    print_policy(current_policy);

    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler (SCHED_FIFO)");
        exit(EXIT_FAILURE);
    }

    printf("\nPolicy changed to SCHED_FIFO with priority %d\n", param.sched_priority);

    current_policy = sched_getscheduler(0);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("New policy:\n");
    print_policy(current_policy);
    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler (SCHED_RR)");
        exit(EXIT_FAILURE);
    }

    printf("\nPolicy changed to SCHED_RR with priority %d\n", param.sched_priority);

    current_policy = sched_getscheduler(0);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("New policy:\n");
    print_policy(current_policy);

    return 0;
}


