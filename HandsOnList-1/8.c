/*
============================================================================
Name : 8.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Output :-  
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>


int main() {

    char line[1024];
	int fd;
    
    fd = open("8example.txt", O_RDONLY);
    
    while(read(fd,line,1)){
	if(line[0] == '\n')
		getchar();
	else
	printf("%c", line[0]);

}

    
    close(fd);

    return 0;
}
