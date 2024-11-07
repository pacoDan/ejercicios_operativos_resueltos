#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>  // Necesario para sleep

// EL EJERCICIO CONSISTE EN IMPRIMIR EN PANTALLA "ABBCABBCABBC.....ABBC"
pthread_t a, b, c;
sem_t sem_a, sem_b, sem_c, sem_x;

void* my_print_a(void* arg) {
    while (1) {
        sem_wait(&sem_a);
        printf("A\n");
        sem_post(&sem_b);
        sem_post(&sem_x);
    }
    return NULL;
}

void* my_print_b(void* arg) {
    while (1) {
        sem_wait(&sem_b);
        sem_wait(&sem_x);
        printf("B\n");
        sem_post(&sem_c);
        sem_post(&sem_x);
    }
    return NULL;
}

void* my_print_c(void* arg) {
    while (1) {
        sem_wait(&sem_c);
        sem_wait(&sem_c);
        sem_wait(&sem_x);
        printf("C\n");
        sem_post(&sem_a);
        sem_post(&sem_b);
    }
    return NULL;
}

int main(void) {
    sem_init(&sem_a, 0, 1);
    sem_init(&sem_b, 0, 1);
    sem_init(&sem_c, 0, 0);
    sem_init(&sem_x, 0, 0);
    puts("ARRANCANDO");

    pthread_create(&a, NULL, my_print_a, NULL);
    pthread_create(&b, NULL, my_print_b, NULL);
    pthread_create(&c, NULL, my_print_c, NULL);

    sleep(2);
    return EXIT_SUCCESS;
}
