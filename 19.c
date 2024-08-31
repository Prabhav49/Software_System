/*
============================================================================
Name : 19.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

output :  PID: 16126
Time taken by getpid() system call: 1844.976077 nano seconds

======================================
*/
#include <stdio.h>
#include <unistd.h>

static inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    double start, end;
    start = rdtsc();
    pid_t pid = getpid();
    end = rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken by getpid() system call: %lf nano seconds\n", (end - start)/2.09);
    
    return 0;
}

