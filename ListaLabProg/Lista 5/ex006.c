#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calcularMedia(int *vetor, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *vetor;
        vetor++;
    }
    return (float)soma / tamanho;
}

float calcularMediana(int *vetor, int tamanho) {
    qsort(vetor, tamanho, sizeof(int), comparar); 

    if (tamanho % 2 == 0) {
        return (vetor[tamanho / 2 - 1] + vetor[tamanho / 2]) / 2.0;
    } else {
        return vetor[tamanho / 2];
    }
}

int calcularModa(int *vetor, int tamanho) {
    int *temp = vetor;
    qsort(temp, tamanho, sizeof(int), comparar); 

    int moda = *temp;
    int maxCount = 0;

    int count = 1;
    for (int i = 1; i < tamanho; i++) {
        if (*temp == *(temp + 1)) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                moda = *temp;
            }
            count = 1;
        }
        temp++;
    }

    if (count > maxCount) {
        moda = *temp;
    }

    return moda;
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

    puts("Valores gerados:\n");
    for (int i = 0; i < tamanho; i++) {
        *vetor = rand() % 100; 
        printf("%d ", *vetor);
        vetor++;
    }
    puts("\n");

    vetor -= tamanho;

    float media = calcularMedia(vetor, tamanho);
    float mediana = calcularMediana(vetor, tamanho);
    int moda = calcularModa(vetor, tamanho);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    free(vetor);

    return 0;
}