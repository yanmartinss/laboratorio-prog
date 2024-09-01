#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encontrarMenorMaior(int *vetor, int tamanho, int **enderecos) {
    int *menor = vetor;
    int *maior = vetor;

    int *ptr = vetor;
    for (int i = 1; i < tamanho; i++) {
        ptr++;
        if (*ptr < *menor) {
            menor = ptr;
        }
        if (*ptr > *maior) {
            maior = ptr;
        }
    }

    enderecos[0] = menor;
    enderecos[1] = maior;
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
    int *ptr = vetor;
    for (int i = 0; i < tamanho; i++) {
        *ptr = rand() % 100; 
        ptr++;
    }

    puts("Vetor gerado: ");
    ptr = vetor;
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    puts("\n");

    int *enderecos[2];

    encontrarMenorMaior(vetor, tamanho, enderecos);

    printf("Menor elemento: %d\n", *enderecos[0]);
    printf("Endereço do menor elemento: %p\n", (void*)enderecos[0]);

    printf("Maior elemento: %d\n", *enderecos[1]);
    printf("Endereço do maior elemento: %p\n", (void*)enderecos[1]);

    free(vetor);

    return 0;
}