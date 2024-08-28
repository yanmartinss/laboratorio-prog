#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, n;

    printf("Digite o valor de N (dimensão da matriz NxN): ");
    scanf("%d", &N);
    printf("Digite o número de elementos em X: ");
    scanf("%d", &n);

    int *X = (int*)malloc(n * sizeof(int));
    int *Y = (int*)malloc(n * sizeof(int));
    if (X == NULL || Y == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    int **M = (int**)malloc(N * sizeof(int*));
    if (M == NULL) {
        printf("Erro de alocação de memória para a matriz M!\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        M[i] = (int*)calloc(N, sizeof(int));
        if (M[i] == NULL) {
            printf("Erro de alocação de memória para as colunas da matriz M!\n");
            return 1;
        }
    }

    srand(time(NULL));

    printf("Vetor X:\n");
    int *ptr_X = X;
    for (int i = 0; i < n; i++, ptr_X++) {
        *ptr_X = rand() % N;
        printf("%d ", *ptr_X);
    }
    printf("\n");

    printf("\nVetor Y:\n");
    int *ptr_Y = Y;
    ptr_X = X; 
    for (int i = 0; i < n; i++, ptr_X++, ptr_Y++) {
        int r = rand() % 10 + 1;  
        if (r <= 3) {
            *ptr_Y = *ptr_X;
        } else if (r <= 5) {
            *ptr_Y = *ptr_X - 1;
        } else if (r <= 7) {
            *ptr_Y = *ptr_X + 1;
        } else if (r <= 9) {
            *ptr_Y = *ptr_X - 2;
        } else {
            *ptr_Y = *ptr_X + 2;
        }

        if (*ptr_Y < 0) {
            *ptr_Y = 0;
        } else if (*ptr_Y >= N) {
            *ptr_Y = N - 1;
        }

        printf("%d ", *ptr_Y);
    }
    printf("\n");

    ptr_X = X;
    ptr_Y = Y;
    for (int i = 0; i < n; i++, ptr_X++, ptr_Y++) {
        M[*ptr_X][*ptr_Y]++;
    }

    printf("\nMatriz M de coocorrências:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    free(X);
    free(Y);
    for (int i = 0; i < N; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}