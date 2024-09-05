/*
============================================================================
Name : 17_tkt_num.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : write a program to simulate online ticket reservation

output : Waiting for Bokking !!
        Current ticket number: 17
        Press Enter to book the ticket...

        New ticket number: 18
        Booking done.
======================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdlib.h>
#include <string.h>

int main() {

    struct {
        int ticket_count;
    } db;

    int fd;
    fd = open("17_example.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Waiting for another user to complete their booking...\n");

    struct flock lock;
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;  
    lock.l_start = 0;        
    lock.l_len = 0;         
    lock.l_pid = getpid();      

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to acquire lock");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);
    read(fd, &db, sizeof(db));

    printf("Current Ticket Number: %d\n", db.ticket_count);
    db.ticket_count++;

    lseek(fd, 0, SEEK_SET);
    write(fd, &db, sizeof(db));
    fsync(fd);

    printf("To Book Ticket, Press Enter...\n");
    getchar();

    lock.l_type = F_UNLCK; 
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to unlock file");
        close(fd);
        return 1;
    }
    printf("Booked\n");
    printf("Your Ticket Number is: %d\n", db.ticket_count);

    close(fd); 

    return 0;
}

