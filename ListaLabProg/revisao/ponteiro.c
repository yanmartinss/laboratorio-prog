#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define RANGE_SIZE 10

int main() {
    int vetor[SIZE], maior;
    char vch[SIZE];
    int *pv = vetor;

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        *(pv + i) = rand() % RANGE_SIZE;
        *(vch + i) = rand() % RANGE_SIZE;
    }

    puts("Vetor de inteiros: ");
    for (int j = 0; j < SIZE; j++) {
        printf("[%p]: %d\n", pv + j, *(pv + j));
    }

    puts("Vetor de char: ");
    for (int z = 0; z < SIZE; z++) {
        printf("[%p]: %d\n", vch + z, *(vch + z));
    }

    int *pvMax = pv;

    for (int k = 1; k < SIZE; k++) {
        pvMax = (*pvMax < *(pv + k)) ? pv + k : pvMax;
    }

    char *pcMax = vch;

    for (int y = 1; y < SIZE; y++) {
        pcMax = (*pcMax < *(vch + y)) ? vch + y : pcMax;
    }

    printf("Endereço do maior inteiro: %p\n", pvMax);
    printf("Endereço do maior char: %p\n", pcMax);

    return 0;
}