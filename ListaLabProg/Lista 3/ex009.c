#include <stdio.h>
#define SIZE 3

int main() {
    int matriz[SIZE][SIZE];

    printf("Digite os elementos da matriz %dx%d:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Elementos da diagonal principal:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("\n");

    return 0;
}
