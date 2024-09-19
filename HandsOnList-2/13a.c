// program1.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_num) {
    if (signal_num == SIGUSR1) {
        printf("Caught SIGUSR1 signal\n");
    }
}

int main() {
    
    signal(SIGUSR1, signal_handler);

    printf("Waiting for SIGUSR1... (try sending SIGSTOP to see the behavior)\n");
    while (1) {
        pause(); 
    }

    return 0;
}
