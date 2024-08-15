#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdlib.h>

int read_and_increment_ticket(const char *file_path) {
    int fd = open(file_path, O_RDWR);
    if (fd != -1) {
        // Obtain an exclusive lock to ensure only one process can read and write at a time
        if (flock(fd, LOCK_EX) != -1) {
            char buffer[20];
            ssize_t len = read(fd, buffer, sizeof(buffer) - 1);
            if (len != -1) {
                buffer[len] = '\0';  // Null-terminate the string
                int ticket_number = atoi(buffer);
                ticket_number++;  // Increment the ticket number

                lseek(fd, 0, SEEK_SET);  // Move the file pointer to the beginning
                snprintf(buffer, sizeof(buffer), "%d", ticket_number);
                write(fd, buffer, strlen(buffer));

                flock(fd, LOCK_UN);  // Release the lock
                close(fd);

                return ticket_number;
            }
        }
        close(fd);
    }
    return -1;  // Return -1 if any operation fails
}

int main() {
    const char *file_path = "/home/prabhav49/IIITB/First Sem/Software_System/Programs_Labs/17_example.txt";  // Change this to your file path
    int new_ticket_number = read_and_increment_ticket(file_path);
    if (new_ticket_number != -1) {
        printf("New ticket number: %d\n", new_ticket_number);
    }
    return 0;
}
