/*
============================================================================
Name : 6.c
Author : Prabhav Pandey
Enrollment Number : MT2024115
Description : Write a simple program to create three threads.

output : Thread 1 is running
        Thread 2 is running
        Thread 3 is running
        All threads have finished

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d is running\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];

    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]) != 0;
    }
    sleep(5);
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL) != 0;
    }

    printf("All threads have finished\n");
    return 0;
}
