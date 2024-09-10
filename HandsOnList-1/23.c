/*
============================================================================
Name : 23.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to create a Zombie state of the running program.

Output :Parent process: PID = 6200
	Child process has exited, but parent is not waiting.
	Child process: PID = 6201

	USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
	prabhav+    6201  0.0  0.0      0     0 pts/0    Z+   11:36   0:00 [a.out] <defunct>
	prabhav+    6222  0.0  0.0   9072  2304 pts/1    S+   11:36   0:00 grep --color=auto Z

======================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        exit(0); //This will create Zommbie Process because child exits without waiting for the parent process.
    }
    else {
        printf("Parent process: PID = %d\n", getpid());
        printf("Child process has exited, but parent is not waiting.\n");

        // Sleep for a while to keep the parent alive while the child becomes a zombie
        sleep(30);
    }

    return 0;
}
