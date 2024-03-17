#include <stdio.h>
#include <limits.h>

int main() {
    int num, maior, menor, produto, cont = 0;

    while (1) {
        printf("Digite um número inteiro (negativo e par para encerrar): ");
        scanf("%d", &num);
        cont += 1;

        if (num < 0 && num % 2 == 0){
            break;
        }
        if (cont == 1){
            maior = num;
            menor = num;
        }

        if (num > maior) {
            maior = num;
        }
        if (num < menor) {
            menor = num;
        }
    }

    produto = maior * menor;

    printf("O produto do maior pelo menor número inserido é: %d\n", produto);

    return 0;
}
