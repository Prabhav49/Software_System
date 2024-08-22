/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem Statement : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void print_file_info(const char *filename) {
    struct stat fileStat;

    // Get file status
    if (stat(filename, &fileStat) == -1) {
        perror("Error getting file information");
        return;
    }

    printf("File: %s\n", filename);
    printf("Inode: %lu\n", (unsigned long)fileStat.st_ino);
    printf("Number of hard links: %lu\n", (unsigned long)fileStat.st_nlink);
    printf("UID: %u\n", (unsigned int)fileStat.st_uid);
    printf("GID: %u\n", (unsigned int)fileStat.st_gid);
    printf("Size: %ld bytes\n", (long)fileStat.st_size);
    printf("Block size: %ld bytes\n", (long)fileStat.st_blksize);
    printf("Number of blocks: %ld\n", (long)fileStat.st_blocks);

   
    char timeBuf[64];
    
   
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_atime));
    printf("Time of last access: %s\n", timeBuf);

   
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));
    printf("Time of last modification: %s\n", timeBuf);

   
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_ctime));
    printf("Time of last status change: %s\n", timeBuf);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    print_file_info(argv[1]);
    return 0;
}
