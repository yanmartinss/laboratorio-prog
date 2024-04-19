#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main() {
    int vetor[SIZE];
    int RANGE_SIZE;

    puts("Digite até que número você quer que seja o número aleatório: ");
    scanf("%d", &RANGE_SIZE);

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        vetor[i] = rand() % RANGE_SIZE;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        int indiceMenor = i;
        for (int k = i + 1; k < SIZE; k++) {
            if (vetor[k] < vetor[indiceMenor]) {
                indiceMenor = k;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }

    printf("Vetor ordenado (método de seleção):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
