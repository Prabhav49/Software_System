/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : write a program to simulate online ticket reservation
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdlib.h>
#include <string.h>


void initialize_ticket_number(const char *file_path) {
    int fd = open(file_path, O_WRONLY | O_CREAT | O_EXCL, 0644);
    if (fd != -1) {

        char buffer[20];
        snprintf(buffer, sizeof(buffer), "%d", 1);
        write(fd, buffer, strlen(buffer));
        close(fd);
    }
}

void read_and_increment_ticket(const char *file_path) {
    int fd = open(file_path, O_RDWR);
    if (fd != -1) {
        if (flock(fd, LOCK_EX) != -1) {
            char buffer[20];
            ssize_t len = read(fd, buffer, sizeof(buffer) - 1);
            if (len != -1) {
                buffer[len] = '\0';  
                int ticket_number = atoi(buffer);
                printf("Current ticket number: %d\n", ticket_number);
                
                 printf("Press Enter to increment the ticket number...\n");
                getchar();

                ticket_number++; 

                lseek(fd, 0, SEEK_SET); 
                snprintf(buffer, sizeof(buffer), "%d", ticket_number);
                write(fd, buffer, strlen(buffer));

                printf("New ticket number: %d\n", ticket_number);
                printf("Booking done.\n");

                flock(fd, LOCK_UN); 
            }
        }
        close(fd);
    }
}

int main() {
    const char *file_path = "/home/prabhav49/IIITB/First Sem/Software_System/Programs_Labs/17_example.txt";  // Change this to your file path
    
       initialize_ticket_number(file_path);
   	printf("Waiting for Bokking !!\n"); 
       read_and_increment_ticket(file_path);
    
    return 0;
}

