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
