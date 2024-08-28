#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *array, size_t tamanho) {
    bool trocou;
    int *ptr1, *ptr2;

    do {
        trocou = false;
        ptr1 = array;
        ptr2 = array + 1;

        for (size_t i = 1; i < tamanho; i++) {
            if (*ptr1 > *ptr2) {
                trocar(ptr1, ptr2);
                trocou = true;
            }
            ptr1++;
            ptr2++;
        }
        tamanho--; 
    } while (trocou);
}

int main() {
    size_t tamanho;

    printf("Digite o número de elementos: ");
    scanf("%zu", &tamanho);

    int *array = (int*)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite os elementos:\n");
    int *ptr = array;
    for (size_t i = 0; i < tamanho; i++) {
        scanf("%d", ptr);
        ptr++;
    }

    bubbleSort(array, tamanho);

    printf("Elementos ordenados:\n");
    ptr = array;
    for (size_t i = 0; i < tamanho; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    free(array);

    return 0;
}
