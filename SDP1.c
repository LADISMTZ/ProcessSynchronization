#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_HILOS 5

pthread_mutex_t block;
int valor = 0;

void* hilo () {
    pthread_mutex_lock(&block);
    valor++;
    pthread_mutex_unlock(&block);
    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[NUM_HILOS];
    pthread_mutex_init(&block, NULL);
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_create(&hilos[i], NULL, hilo, NULL);
    }
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL);
    }
    printf("El numero del contador es: %d\n", valor);
    pthread_mutex_destroy(&block);
    return 0;
}

