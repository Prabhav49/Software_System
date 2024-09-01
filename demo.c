#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    pid_t child;

    child = fork();
    if(child == 0){

        printf("I am child process with %d pid\n", getpid());
        printf("My parent pid is : %d \n", getppid());
         exit(0);
    }
    else{

        sleep(10);
        printf("I am parent process with %d pid\n", getpid());
        printf("My child pid is : %d \n", child);
       

    }
}
