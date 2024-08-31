/*
============================================================================
Name : 28.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to get maximum and minimum real time priority.

Output :Real-time priorities for SCHED_FIFO:
        Maximum priority: 99
        Minimum priority: 1

        Real-time priorities for SCHED_RR:
        Maximum priority: 99
        Minimum priority: 1
 
======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int max_priority_fifo, min_priority_fifo;
    int max_priority_rr, min_priority_rr;

    max_priority_fifo = sched_get_priority_max(SCHED_FIFO);
    min_priority_fifo = sched_get_priority_min(SCHED_FIFO);

    max_priority_rr = sched_get_priority_max(SCHED_RR);
    min_priority_rr = sched_get_priority_min(SCHED_RR);

    if (max_priority_fifo == -1 || min_priority_fifo == -1 ||
        max_priority_rr == -1 || min_priority_rr == -1) {
        perror("sched_get_priority_max/min");
        exit(EXIT_FAILURE);
    }

    printf("Real-time priorities for SCHED_FIFO:\n");
    printf("Maximum priority: %d\n", max_priority_fifo);
    printf("Minimum priority: %d\n", min_priority_fifo);

    printf("\nReal-time priorities for SCHED_RR:\n");
    printf("Maximum priority: %d\n", max_priority_rr);
    printf("Minimum priority: %d\n", min_priority_rr);

    return 0;
}
