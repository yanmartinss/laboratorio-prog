#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX_VALUE 10

int main() {
    int x[N];
    int y[MAX_VALUE + 1] = {0};

    srand(time(NULL));

    printf("Vetor x:\n");
    for (int i = 0; i < N; i++) {
        x[i] = rand() % (MAX_VALUE + 1);
        printf("%d ", x[i]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        y[x[i]]++;
    }

    printf("Vetor y:\n");
    for (int i = 0; i <= MAX_VALUE; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    return 0;
}