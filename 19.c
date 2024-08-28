/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Output : PID: 4816
Time taken by getpid() system call: 19692 clock cycles

*/

#include <stdio.h>
#include <unistd.h>

static inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    start = rdtsc();
    pid_t pid = getpid();
    end = rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken by getpid() system call: %llu clock cycles\n", end - start);
    
    return 0;
}

