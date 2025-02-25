//Calculate the sum of an array using multiple threads (with pthreads). The code has a race condition when updating the shared sum variable.
 //Code:

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000

int arr[ARRAY_SIZE];
int global_sum = 0;

void* partial_sum(void* arg) {
    int start = *(int*)arg;
    int end = start + ARRAY_SIZE / NUM_THREADS;
    for (int i = start; i < end; i++) {
        global_sum += arr[i];
    }
    return NULL;
}

int main() {
    // Initialize array with values 1 to ARRAY_SIZE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i + 1;
    }
    
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i * (ARRAY_SIZE / NUM_THREADS);
        pthread_create(&threads[i], NULL, partial_sum, &thread_args[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Total sum is: %d\n", global_sum);
    return 0;
}

//Expected Output:

//Total sum is: 500500

