#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE_SIZE 21
#define ROWS 3
#define COLS 3

int main() {
    int matriz[ROWS][COLS], x, cont = 0;
    int *ptr = &matriz[0][0];

    srand(time(NULL));

    for (int i = 0; i < ROWS * COLS; i++) {
        *(ptr + i) = rand() % RANGE_SIZE;
    }

    puts("Matriz gerada:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", *(ptr + i * COLS + j));
        }
        puts("\n");
    }

    puts("\nDigite um valor inteiro para procurar na matriz: ");
    scanf("%d", &x);

    for (int i = 0; i < ROWS * COLS; i++) {
        if (*(ptr + i) == x) {
            cont++;
        }
    }

    printf("\nO valor %d aparece %d vezes na matriz.\n", x, cont);

    return 0;
}