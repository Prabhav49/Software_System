/*
============================================================================
Name : 4.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
              system call. Use time stamp counter.

output : CElapsed time: 53540.67 ns

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    uint32_t low, high;
    __asm__ __volatile__ (
        "rdtsc"
        : "=a" (low), "=d" (high)
    );
    return ((uint64_t)high << 32) | low;
}

int main() {
    uint64_t start, end;
    pid_t ppid;
    start = rdtsc();

    for (int i = 0; i < 100; i++) {
        ppid = getppid();
    }
    end = rdtsc();
    printf("Elapsed time: %.2f ns\n", (double)(end - start)/2.09);

    return 0;
}
