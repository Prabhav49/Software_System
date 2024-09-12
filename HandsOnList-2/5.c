/*
============================================================================
Name : 4.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to print the system limitation of
            a. maximum length of the arguments to the exec family of functions.
            b. maximum number of simultaneous process per user id.
            c. number of clock ticks (jiffy) per second.
            d. maximum number of open files
            e. size of a page
            f. total number of pages in the physical memory
            g. number of currently available pages in the physical memory.

            output : Maximum length of arguments to exec functions: 2097152 bytes
                        Maximum number of simultaneous processes per user ID: 30700
                        Number of clock ticks (jiffies) per second: 100
                        Maximum number of open files: 1048576
                        Size of a page: 4096 bytes
                        Total number of pages in physical memory: 2034677760
                        Number of currently available pages in physical memory: 502531072

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/param.h>
#include <sys/sysinfo.h>
#include <sys/vfs.h>
#include <sys/mman.h>

int main() {
    printf("Maximum length of arguments to exec functions: %ld bytes\n", sysconf(_SC_ARG_MAX));
    printf("Maximum number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Number of clock ticks (jiffies) per second: %ld\n", sysconf(_SC_CLK_TCK));

    struct rlimit rl;
    if (getrlimit(RLIMIT_NOFILE, &rl) == 0) {
        printf("Maximum number of open files: %lld\n", (long long)rl.rlim_max);
    } else {
        perror("getrlimit");
    }
    printf("Size of a page: %ld bytes\n", sysconf(_SC_PAGESIZE));

    struct sysinfo si;
    if (sysinfo(&si) == 0) {
        printf("Total number of pages in physical memory: %lu\n", si.totalram / (sysconf(_SC_PAGESIZE) / 1024));
    } else {
        perror("sysinfo");
    }

    if (sysinfo(&si) == 0) {
        printf("Number of currently available pages in physical memory: %lu\n", si.freeram / (sysconf(_SC_PAGESIZE) / 1024));
    } else {
        perror("sysinfo");
    }
    return 0;
}
