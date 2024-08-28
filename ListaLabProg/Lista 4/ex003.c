#include <stdio.h>
#include <limits.h>

void verificarMenor(int *atual, int *menor) {
    if (*atual < *menor) {
        *menor = *atual;
    }
}

int main() {
    int num;
    int menor = INT_MAX;
    int *ptr_num = &num, *ptr_menor = &menor;

    while (1) {
        puts("Digite um número (ou um número negativo para sair): ");
        scanf("%d", ptr_num);

        if (*ptr_num < 0) {
            break;
        }

        verificarMenor(ptr_num, ptr_menor);

        printf("O menor valor fornecido até agora é: %d\n", *ptr_menor);
    }

    printf("Programa encerrado. O menor valor fornecido foi: %d\n", *ptr_menor);

    return 0;
}