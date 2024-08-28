#include <stdio.h>
#include <stdlib.h>

void imprimirValoresEEnderecos(char *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Valor do vetor[%d]: %c, Endereço: %p\n", i, vetor[i], (void*)&vetor[i]);
    }
}

int main() {
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    char *vetor = (char*)malloc(tamanho * sizeof(char));

    if (vetor == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1; 
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para vetor[%d]:\n ", i);
        scanf(" %c", &vetor[i]);
    }

    printf("\nValores e endereços do vetor:\n");
    imprimirValoresEEnderecos(vetor, tamanho);

    free(vetor);

    return 0;
}

/*Observações sobre os endereços:
Ao observar os endereços de memória dos elementos dos vetores, você deve perceber que:

Endereços consecutivos:
Os endereços dos elementos do vetor são consecutivos, mas a diferença entre eles depende do tamanho do tipo de dado.

Tamanho do tipo de dado:
Em um vetor de int, os endereços dos elementos diferem geralmente por 4 bytes (assumindo que int tem 4 bytes no seu sistema).
Em um vetor de float, os endereços também diferem por 4 bytes (assumindo que float tem 4 bytes).
Em um vetor de char, os endereços diferem por 1 byte, porque char tem 1 byte.*/