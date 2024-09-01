#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarVetor(int *vetor, int tamanho, int limite) {
    for (int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % limite;
    }
}

void inicializarMatriz(int **matriz, int tamanho) {
    int *p;
    for (int i = 0; i < tamanho; i++) {
        p = *(matriz + i);
        for (int j = 0; j < tamanho; j++) {
            *p = 0;
            p++;
        }
    }
}

void preencherMatriz(int *vetorX, int *vetorY, int **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int x = *(vetorX + i);
        int y = *(vetorY + i);
        if (x < tamanho && y < tamanho) {
            (*(*(matriz + x) + y))++; 
        }
    }
}

void exibirMatriz(int **matriz, int tamanho) {
    int *p;
    for (int i = 0; i < tamanho; i++) {
        p = *(matriz + i);
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", *p);
            p++;
        }
        puts("\n");
    }
}

int main() {
    int tamanho;
    int *vetorX, *vetorY;
    int **matriz;

    srand(time(NULL));

    puts("Digite o tamanho dos vetores e matriz NxN: ");
    scanf("%d", &tamanho);

    vetorX = (int *)malloc(tamanho * sizeof(int));
    vetorY = (int *)malloc(tamanho * sizeof(int));
    matriz = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        *(matriz + i) = (int *)malloc(tamanho * sizeof(int));
    }

    if (vetorX == NULL || vetorY == NULL || matriz == NULL) {
        puts("Erro na alocação de memória.\n");
        return 1;
    }

    gerarVetor(vetorX, tamanho, tamanho);
    gerarVetor(vetorY, tamanho, tamanho);
    inicializarMatriz(matriz, tamanho);

    preencherMatriz(vetorX, vetorY, matriz, tamanho);

    puts("Vetor X: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetorX + i));
    }
    puts("\n");

    puts("Vetor Y: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetorY + i));
    }
    puts("\n");

    puts("Matriz de coocorrências:\n");
    exibirMatriz(matriz, tamanho);

    free(vetorX);
    free(vetorY);
    for (int i = 0; i < tamanho; i++) {
        free(*(matriz + i));
    }
    free(matriz);

    return 0;
}