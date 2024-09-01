#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(float *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *vetor = ((float)rand() / (float)(RAND_MAX)) * 100.0; 
        vetor++;
    }
}

float somarVetor(float *vetor, int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *vetor;
        vetor++;
    }
    return soma;
}

int main() {
    int tamanho;

    puts("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        puts("A quantidade de elementos deve ser maior que zero.\n");
        return 1;
    }

    float *vetor = (float *)malloc(tamanho * sizeof(float));
    if (vetor == NULL) {
        puts("Erro na alocação de memória.\n");
        return 1;
    }

    srand(time(NULL));

    preencherVetor(vetor, tamanho);

    puts("Valores gerados:\n");
    float *temp = vetor; 
    for (int i = 0; i < tamanho; i++) {
        printf("vetor[%d] = %.2f\n", i, *temp);
        temp++;
    }

    float soma = somarVetor(vetor, tamanho);

    printf("\nA soma dos elementos do vetor é: %.2f\n", soma);

    free(vetor);

    return 0;
}