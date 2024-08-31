/*
============================================================================
Name : 18.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to perform Record locking.
                a. Implement write lock
                b. Implement read lock
                Create three records in a file. Whenever you access a particular record, first lock it then modify/access
                to avoid race condition.

output :  Selecting Train Number : 
            Select Train number: (1 2 3): 
            2
            Waiting for another user to complete their booking...
            Current Ticket Number: 3
            To Book Ticket, Press Enter... 

            Any other process wants to access 2 train number :
            Select Train number: (1 2 3): 
            2
            Waiting for another user to complete their booking...

            After first user done booking : 
            Booked
            Your Ticket Number is: 4
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
        int input;
        int ticket_count;
    } db;

    int fd, input;
    fd = open("18_record.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Select Train number: (1 2 3): \n");
    scanf("%d", &input);

    printf("Waiting for another user to complete their booking...\n");

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();

    fcntl(fd, F_SETLKW, &lock);

    lseek(fd, lock.l_start, SEEK_SET);
    read(fd, &db, sizeof(db));

   
    printf("Current Ticket Number: %d\n", db.ticket_count);

    db.ticket_count++;

    lseek(fd, lock.l_start, SEEK_SET);
    write(fd, &db, sizeof(db));
    fsync(fd);

    printf("To Book Ticket, Press Enter... \n");
    getchar();
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Booked\n");
    printf("Your Ticket Number is: %d\n", db.ticket_count);

    // Close the file
    close(fd);

    return 0;
}
