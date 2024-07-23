#include <stdio.h>
#include <limits.h>

int main() {
    int num, menor;
    int *ptr_num = &num;
    int *ptr_menor = &menor;

    *ptr_menor = INT_MAX;

    puts("Digite números (digite um número negativo para finalizar):\n");

    while (1) {
        puts("Digite um número: ");
        scanf("%d", ptr_num);

        if (*ptr_num < 0) {
            break;
        }

        if (*ptr_num < *ptr_menor) {
            *ptr_menor = *ptr_num;
        }

        printf("O menor valor fornecido até agora é: %d\n", *ptr_menor);
    }

    puts("Programa finalizado.\n");

    return 0;
}