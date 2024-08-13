#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float soma = 0, media;

    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite %d numeros inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / n;

    printf("A media eh: %.2f\n", media);

    printf("Numeros acima da media:\n");
    for (int i = 0; i < n; i++) {
        if (vetor[i] > media) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");

    free(vetor);

    return 0;
}