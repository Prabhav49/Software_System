/*
============================================================================
Name : 15.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a program to display the environmental variable of the user (use environ).

output : Environment Variables:
            SHELL=/bin/bash
            SESSION_MANAGER=local/prabhav-pandey:@/tmp/.ICE-unix/1970,unix/prabhav-pandey:/tmp/.ICE-unix/1970
            QT_ACCESSIBILITY=1
            COLORTERM=truecolor
            XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
            SSH_AGENT_LAUNCHER=openssh
            XDG_MENU_PREFIX=gnome-
            GNOME_DESKTOP_SESSION_ID=this-is-deprecated
            GNOME_KEYRING_CONTROL=/run/user/1000/keyring
            JAVA_HOME=/home/prabhav49/jdk-22.0.2/
            GNOME_SHELL_SESSION_MODE=ubuntu
            SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
            XMODIFIERS=@im=ibus
...............
============================================================================
*/


#include <stdio.h>

// extern char **environ declares that the variable is defined elsewhere
extern char **environ;

int main() {
    int i = 0;
    char **env = environ;  // Access the global environment variable array

    printf("Environment Variables:\n");

   
    while (env[i] != NULL) {
        printf("%s\n", env[i]);
        i++;
    }

    return 0;
}

