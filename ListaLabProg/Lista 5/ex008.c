#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = rand() % 100; 
        }
    }
}

void binarizarMatriz(int **matriz, int **matrizBinaria, int linhas, int colunas, int limiar) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizBinaria[i][j] = (matriz[i][j] > limiar) ? 1 : 0;
        }
    }
}

void exibirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        puts("\n");
    }
}

int main() {
    int linhas, colunas, limiar;

    srand(time(NULL));

    puts("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    puts("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);
    puts("Digite o limiar para binarização: ");
    scanf("%d", &limiar);

    int **matrizM = (int **)malloc(linhas * sizeof(int *));
    int **matrizS = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matrizM[i] = (int *)malloc(colunas * sizeof(int));
        matrizS[i] = (int *)malloc(colunas * sizeof(int));
    }

    if (matrizM == NULL || matrizS == NULL) {
        puts("Erro na alocação de memória.\n");
        return 1;
    }

    puts("Matriz M gerada:\n");
    preencherMatriz(matrizM, linhas, colunas);
    exibirMatriz(matrizM, linhas, colunas);

    binarizarMatriz(matrizM, matrizS, linhas, colunas, limiar);
    puts("Matriz binária S:\n");
    exibirMatriz(matrizS, linhas, colunas);

    for (int i = 0; i < linhas; i++) {
        free(matrizM[i]);
        free(matrizS[i]);
    }
    free(matrizM);
    free(matrizS);

    return 0;
}