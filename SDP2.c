#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t block;
pthread_barrier_t alto;
int hello_written = 0;

void* hello () {
    printf("Hola ");
    hello_written = 1;
    pthread_barrier_wait(&alto);
    pthread_exit(NULL);
}

void* world () {
    pthread_barrier_wait(&alto);
    printf("mundo\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t hilo1, hilo2;
    pthread_mutex_init(&block, NULL);
    pthread_barrier_init(&alto, NULL, 2);
    pthread_create(&hilo1, NULL, hello, NULL);
    pthread_create(&hilo2, NULL, world, NULL);
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_mutex_destroy(&block);
    pthread_barrier_destroy(&alto);

    return 0;
}
