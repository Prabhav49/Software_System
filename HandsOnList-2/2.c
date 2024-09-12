/*
============================================================================
Name : 2.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to print the system resource limits. Use getrlimit system call.

output : Resource: 9
    Soft limit: -1
    Hard limit: -1
Resource: 4
    Soft limit: 0
    Hard limit: -1
Resource: 0
    Soft limit: -1
    Hard limit: -1................

============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

void print_resource_limit(int resource) {
    struct rlimit rl;
    if (getrlimit(resource, &rl) == 0) {
        printf("Resource: %d\n", resource);
        printf("    Soft limit: %lld\n", (long long)rl.rlim_cur);
        printf("    Hard limit: %lld\n", (long long)rl.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {

    print_resource_limit(RLIMIT_AS);        
    print_resource_limit(RLIMIT_CORE);      
    print_resource_limit(RLIMIT_CPU);       
    print_resource_limit(RLIMIT_DATA);     
    print_resource_limit(RLIMIT_FSIZE);     
    print_resource_limit(RLIMIT_NOFILE);   
    print_resource_limit(RLIMIT_STACK);     
    print_resource_limit(RLIMIT_NPROC);   
    print_resource_limit(RLIMIT_MEMLOCK);  
    print_resource_limit(RLIMIT_LOCKS);    
    print_resource_limit(RLIMIT_SIGPENDING); 
    print_resource_limit(RLIMIT_MSGQUEUE);  
    print_resource_limit(RLIMIT_NICE);    
    print_resource_limit(RLIMIT_RTPRIO);   
    print_resource_limit(RLIMIT_RSS);    
    // print_resource_limit(RLIMIT_NDELAY);   

    return 0;
}
