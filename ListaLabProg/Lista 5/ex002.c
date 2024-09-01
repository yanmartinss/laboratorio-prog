#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int* encontrarMenor(int *vetor, int tamanho) {
    int *menor = vetor;
    for (int i = 1; i < tamanho; i++) {
        menor = (MIN(*(vetor + i), *menor) == *(vetor + i)) ? (vetor + i) : menor;
    }
    return menor;
}

int main() {
    int tamanho;

    puts("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        puts("A quantidade de elementos deve ser maior que zero.\n");
        return 1;
    }

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        puts("Erro na alocação de memória.\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % 100; 
    }

    puts("Vetor gerado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }
    puts("\n");

    int *menorElemento = encontrarMenor(vetor, tamanho);

    printf("Menor elemento: %d\n", *menorElemento);
    printf("Endereço do menor elemento: %p\n", (void*)menorElemento);

    free(vetor);

    return 0;
}