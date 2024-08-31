/*
============================================================================
Name : 27b.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : b. excelp

Ouput : Executing 'ls -Rl' using execl...
.:
total 216
-rw-rw-r-- 1 prabhav49 prabhav49  1361 Aug 31 17:50 10a.c
-rw-rw-r-- 1 prabhav49 prabhav49  1127 Aug 31 18:15 10b.c
-rw-rw-r-- 1 prabhav49 prabhav49    30 Aug 31 17:50 10b_example.txt
-rw-rw-r-- 1 prabhav49 prabhav49  1579 Aug 31 17:52 11.c
-rw-rw-r-- 1 prabhav49 prabhav49   210 Aug 31 17:52 11example.txt
-rw-rw-r-- 1 prabhav49 prabhav49  1619 Aug 31 17:54 12.c
-rw-rw-r-- 1 prabhav49 prabhav49  1524 Aug 31 18:12 13.c
-rw-rw-r-- 1 prabhav49 prabhav49  1746 Aug 31 18:13 14.c
-rw-rw-r-- 1 prabhav49 prabhav49  1360 Aug 31 18:14 15.c
-rw-rw-r-- 1 prabhav49 prabhav49  1574 Aug 31 18:18 16a.c
-rw-rw-r-- 1 prabhav49 prabhav49     0 Aug 15 17:48 16_a_example.txt
-rw-rw-r-- 1 prabhav49 prabhav49  1714 Aug 31 18:19 16b.c
-rw-rw-r-- 1 prabhav49 prabhav49     2 Aug 31 18:19 17_example.txt
-rw-rw-r-- 1 prabhav49 prabhav49  2030 Aug 31 18:20 17_tkt_num. ...........................
======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing 'ls -Rl' using execlp...\n");
    execlp("ls", "ls", "-Rl", NULL);
    printf("Failed to execute 'ls -Rl' using execlp.\n");
    return 0;
}
