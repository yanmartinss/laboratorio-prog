#include <stdio.h>

int main() {
    int size;
    char type;

    puts("Escolha o tipo de vetor (i para int, f para float, c para char): ");
    scanf(" %c", &type);

    puts("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    if (type == 'i') {
        int array[size];
        for (int i = 0; i < size; i++) {
            printf("Digite o valor para array[%d]: ", i);
            scanf("%d", &array[i]);
        }
        printf("\nValores e endereços do vetor de inteiros:\n");
        for (int i = 0; i < size; i++) {
            printf("Valor: %d, Endereço: %p\n", array[i], (void*)&array[i]);
        }
    } else if (type == 'f') {
        float array[size];
        for (int i = 0; i < size; i++) {
            printf("Digite o valor para array[%d]: ", i);
            scanf("%f", &array[i]);
        }
        puts("\nValores e endereços do vetor de floats:\n");
        for (int i = 0; i < size; i++) {
            printf("Valor: %.2f, Endereço: %p\n", array[i], (void*)&array[i]);
        }
    } else if (type == 'c') {
        char array[size];
        for (int i = 0; i < size; i++) {
            printf("Digite o valor para array[%d]: ", i);
            scanf(" %c", &array[i]);
        }
        puts("\nValores e endereços do vetor de chars:\n");
        for (int i = 0; i < size; i++) {
            printf("Valor: %c, Endereço: %p\n", array[i], (void*)&array[i]);
        }
    } else {
        puts("Tipo inválido!\n");
    }

    return 0;
}

/*
Observei que o endereço em que vai os inteiros e os números com tipo float é o mesmo mas o de tipo char vão para outros endereços.
*/