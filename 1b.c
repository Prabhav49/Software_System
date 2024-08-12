/*
Name : Prabhav Pandey
Enroll : MT2024115
Problem : 1. Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)

*/
#include <unistd.h>
#include <stdio.h>

int main(void) {
    const char *target = "./1newFile"; // The original file you want to link to
    const char *linkname = "hardlnk_demo"; // The name of the hard link to create

    // Create a hard link
    int result = link(target, linkname);

    // Check if the hard link was created successfully
    if (result == 0) {
        printf("Success: Hard link '%s' created, pointing to '%s'.\n", linkname, target);
    } else {
        perror("Error");
        printf("Failure: Could not create hard link.\n");
    }

    return 0;
}
