#include <stdio.h>

int main() {
    int num, menor, count = 1;
    int *ptr_num = &num, *ptr_menor = &menor;

    puts("Digite um valor para num (DIGITE ALGUM NEGATIVO PARA ENCERRAR): ");
    scanf("%d", ptr_num);

    while (1) {
        if (*ptr_num < 0) {
            break;
        }

        if (count) {
            *ptr_menor = *ptr_num;
            count = 0;
        } else if (*ptr_num < *ptr_menor) {
            *ptr_menor = *ptr_num;
        }
        printf("Menor numero: %d\n", *ptr_menor);

        puts("Digite um valor para num (DIGITE ALGUM NEGATIVO PARA ENCERRAR): ");
        scanf("%d", ptr_num);
    }
    
    return 0;
}