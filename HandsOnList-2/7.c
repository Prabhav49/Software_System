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
