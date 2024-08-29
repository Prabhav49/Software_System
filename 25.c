/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement :Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call). 

Output :
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2, child3;

    child1 = fork();
    if (child1 == 0) {

        printf("First child (PID: %d) created.\n", getpid());
        sleep(2);
        exit(0);
    }

    child2 = fork();
    if (child2 == 0) {
        printf("Second child (PID: %d) created.\n", getpid());
        sleep(4);
        exit(0);
    }

    child3 = fork();
    if (child3 == 0) {
        printf("Third child (PID: %d) created.\n", getpid());
        sleep(6);
        exit(0);
    }
    //Parent waiting for second child ... (say)
    printf("Parent waiting for the second child (PID: %d)...\n", child2);
    waitpid(child2, NULL, 0);
    printf("Second child (PID: %d) terminated.\n", child2);

    wait(NULL);
    wait(NULL);

    printf("Parent process completed.\n");
    return 0;
}
