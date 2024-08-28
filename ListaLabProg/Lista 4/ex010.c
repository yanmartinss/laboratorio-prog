#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, n;

    printf("Digite o valor de N (intervalo de 0 a N-1): ");
    scanf("%d", &N);
    printf("Digite o número de elementos em X: ");
    scanf("%d", &n);

    int *X = (int*)malloc(n * sizeof(int));
    int *F = (int*)calloc(N, sizeof(int)); 
    if (X == NULL || F == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    srand(time(NULL));

    printf("Vetor X:\n");
    for (int i = 0; i < n; i++) {
        X[i] = rand() % N;
        printf("%d ", X[i]);
        F[X[i]]++;  
    }
    printf("\n");

    printf("Vetor F:\n");
    for (int i = 0; i < N; i++) {
        printf("F[%d] = %d\n", i, F[i]);
    }

    free(X);
    free(F);

    return 0;
}