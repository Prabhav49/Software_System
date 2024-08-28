/*
Name : Prabhav Pandey
Enroll : MT2024115
Probelm Statement :Find out the priority of your running program. Modify the priority with nice command.

Output :Current Priority of PID 5207: 0
Priority successfully changed by 5
Modified Priority of PID 5207: 5
 
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid();
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Current Priority of PID %d: %d\n", pid, priority);

    int val = 5;  // Increment the priority by 5
    int ret = nice(val);

    if (ret == -1) {
        perror("Failed to change priority using nice");
    } else {
        printf("Priority successfully changed by %d\n", val);
    }
    
    priority = getpriority(PRIO_PROCESS, pid);
    printf("Modified Priority of PID %d: %d\n", pid, priority);
    
    return 0;
}

