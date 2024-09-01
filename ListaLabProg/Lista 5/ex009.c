#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int **matriz, int tamanho) {
    int *p;
    for (int i = 0; i < tamanho; i++) {
        p = matriz[i];
        for (int j = 0; j < tamanho; j++) {
            *p = rand() % 100; 
            p++;
        }
    }
}

int somaDiagonalPrincipal(int **matriz, int tamanho) {
    int soma = 0;
    int *p;
    for (int i = 0; i < tamanho; i++) {
        p = matriz[i] + i; 
        soma += *p;
    }
    return soma;
}

void exibirMatriz(int **matriz, int tamanho) {
    int *p;
    for (int i = 0; i < tamanho; i++) {
        p = matriz[i];
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", *p);
            p++;
        }
        puts("\n");
    }
}

int main() {
    int tamanho;

    srand(time(NULL));

    puts("Digite o tamanho da matriz N x N: ");
    scanf("%d", &tamanho);

    int **matriz = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        matriz[i] = (int *)malloc(tamanho * sizeof(int));
    }

    if (matriz == NULL) {
        puts("Erro na alocação de memória.\n");
        return 1;
    }

    puts("Matriz gerada:\n");
    preencherMatriz(matriz, tamanho);
    exibirMatriz(matriz, tamanho);

    int soma = somaDiagonalPrincipal(matriz, tamanho);
    printf("Soma da diagonal principal: %d\n", soma);
    if (soma % 2 == 0) {
        puts("A soma é par.\n");
    } else {
        puts("A soma é ímpar.\n");
    }

    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}