/*
============================================================================
Name : 7.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a simple program to print the created thread ids.
output :Thread ID: 139791664412352
        Thread ID: 139791647626944
        Thread ID: 139791656019648
        All threads have finished

============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL) != 0;
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL) != 0;
    }

    printf("All threads have finished\n");
    return 0;
}
