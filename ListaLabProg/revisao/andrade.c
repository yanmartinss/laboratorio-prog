#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_SIZE 100

int main() {
    int qnt;
    int *ptr_qnt = &qnt;

    puts("Digite o tamanho do vetor: ");
    scanf("%d", ptr_qnt);

    int vetor[*ptr_qnt];
    int *ptr_vetor = vetor;

    srand(time(NULL));
    for (int i = 0; i < *ptr_qnt; i++) {
        *(ptr_vetor + i) = rand() % RANGE_SIZE;
    }

    puts("Vetor aleatório:");
    for (int i = 0; i < *ptr_qnt; i++) {
        printf("%d\n", *(ptr_vetor + i));
    }

    for (int i = 0; i < *ptr_qnt - 1; i++) {
        for (int j = 0; j < *ptr_qnt - 1 - i; j++) {
            if (*(ptr_vetor + j) > *(ptr_vetor + j + 1)) {
                int temp = *(ptr_vetor + j);
                *(ptr_vetor + j) = *(ptr_vetor + j + 1);
                *(ptr_vetor + j + 1) = temp;
            }
        }
    }

    puts("Vetor ordenado:");
    for (int i = 0; i < *ptr_qnt; i++) {
        printf("%d\n", *(ptr_vetor + i));
    }

    int soma = 0;
    for (int i = 0; i < *ptr_qnt; i++) {
        soma += *(ptr_vetor + i);
    }
    printf("Soma dos elementos do vetor: %d\n", soma);

    float mediana;
    if (*ptr_qnt % 2 == 0) {
        mediana = (*(ptr_vetor + (*ptr_qnt / 2 - 1)) + *(ptr_vetor + (*ptr_qnt / 2))) / 2.0;
    } else {
        mediana = *(ptr_vetor + (*ptr_qnt / 2));
    }
    printf("Mediana do vetor: %.2f\n", mediana);

    return 0;
}