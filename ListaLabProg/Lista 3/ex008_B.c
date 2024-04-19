#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int vetor[SIZE];
    int RANGE_SIZE, intervaloFim;

    puts("Digite até que número você quer que seja o número aleatório: ");
    scanf("%d", &RANGE_SIZE);

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        vetor[i] = rand() % RANGE_SIZE;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int k = 0; k < SIZE - i - 1; k++) {
            if (vetor[k] > vetor[k + 1]) {
                int aux = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = aux;
            }
        }
    }

    printf("Vetor ordenado:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
