#include <stdio.h>

int main() {
    int num, menor, cont = 1;
    int *ptr_num = &num;
    int *ptr_menor = &menor;

    while (1) {
        puts("Digite um número (NEGATIVO PARA ENCERRAR O PROGRAMA): ");
        scanf("%d", ptr_num);

        if (*ptr_num < 0) {
            break;
        }

        if (cont) {
            *ptr_menor = *ptr_num;
            cont = 0;
        } else if (*ptr_num < *ptr_menor) {
            *ptr_menor = *ptr_num;
        }

        printf("O menor valor fornecido até agora é: %d\n", *ptr_menor);
    }

    return 0;
}