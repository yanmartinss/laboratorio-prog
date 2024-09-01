#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *vetor = rand() % 100; 
        vetor++;
    }
}

float calcularEMQ(int *vetorA, int *vetorB, int tamanho) {
    float somaQuadrados = 0;
    for (int i = 0; i < tamanho; i++) {
        int diferenca = *vetorA - *vetorB;
        somaQuadrados += (diferenca * diferenca);
        vetorA++;
        vetorB++;
    }
    return somaQuadrados / tamanho;
}

int main() {
    int tamanho;

    puts("Digite a quantidade de elementos dos vetores: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        puts("A quantidade de elementos deve ser maior que zero.\n");
        return 1;
    }

    int *vetorA = (int *)malloc(tamanho * sizeof(int));
    int *vetorB = (int *)malloc(tamanho * sizeof(int));
    if (vetorA == NULL || vetorB == NULL) {
        puts("Erro na alocação de memória.\n");
        return 1;
    }

    srand(time(NULL));

    puts("Valores do vetor A:\n");
    int *tempA = vetorA; 
    for (int i = 0; i < tamanho; i++) {
        *tempA = rand() % 100; 
        printf("%d ", *tempA);
        tempA++;
    }
    puts("\n");

    puts("Valores do vetor B:\n");
    int *tempB = vetorB; 
    for (int i = 0; i < tamanho; i++) {
        *tempB = rand() % 100; 
        printf("%d ", *tempB);
        tempB++;
    }
    puts("\n");

    tempA = vetorA;
    tempB = vetorB;

    float emq = calcularEMQ(tempA, tempB, tamanho);
    printf("Erro Médio Quadrático (EMQ): %.2f\n", emq);

    free(vetorA);
    free(vetorB);

    return 0;
}