#include <stdio.h>

#define SIZE 3
#define T 5

int main() {
    int MATRIZ_X[SIZE][SIZE];
    int MATRIZ_Y[SIZE][SIZE];

    puts("Digite os elementos da matriz X:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("MATRIZ_X[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &MATRIZ_X[i][j]);
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (MATRIZ_X[i][j] > T) {
                MATRIZ_Y[i][j] = 1;
            } else {
                MATRIZ_Y[i][j] = 0;
            }
        }
    }

    puts("\n MATRIZ Y:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", MATRIZ_Y[i][j]);
        }
        puts("\n");
    }

    return 0;
}