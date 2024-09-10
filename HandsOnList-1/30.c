/*
============================================================================
Name : 28.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to run a script at a specific time using a Daemon process.

Output: Daemon process is running...
		Child pid: 5d
		Daemon process is running...
======================================
*/
#include <unistd.h>
#include<sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	if(!fork()) {
		setsid();
		chdir("/");
		umask(0);
			while(1){
				sleep(5);
				printf("Child pid: 5d\n", getpid());
				printf("Daemon process is running...\n");
			}
}
	else exit(0);
 
}
