/*
Name : Prabhav Pandey
Enrollment Number : MT2024115
Problem Statement : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
*/

#include <unistd.h>
#include <stdio.h>

int main(void) {
    const char *target = "./1newFile"; // The file you want to link to
    const char *linkname = "sftlnk_demo"; // The name of the symlink to create

    // Create a symbolic link
    int result = symlink(target, linkname);

    // Check if the symlink was created successfully
    if (result == 0) {
        printf("Success: Symbolic link '%s' created, pointing to '%s'.\n", linkname, target);
    } else {
        perror("Error");
        printf("Failure: Could not create symbolic link.\n");
    }

    return 0;
}
