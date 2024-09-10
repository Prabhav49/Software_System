#include <stdio.h>
#include <sys/resource.h>
#include <limits.h>

int main() {
    struct rlimit rl;

    if (getrlimit(RLIMIT_FSIZE, &rl) == -1) {
        perror("getrlimit");
        return 1;
    }

    printf("Current file size limit: %lld bytes\n", (long long)rl.rlim_cur);

    rl.rlim_cur = 1024 * 512 * 128; 

    setrlimit(RLIMIT_FSIZE, &rl) == -1;
    getrlimit(RLIMIT_FSIZE, &rl) == -1;
    printf("New file size limit: %lld MB\n", (long long)rl.rlim_cur/1048576);

    return 0;
}
