#include <stdio.h>

int main() {
    int num, cont = 0, digito;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    while (num != 0) {
        digito = num % 10;
        if (digito == 7) {
            cont++;
        }
        num /= 10;
    }

    printf("O número de dígitos 7 no inteiro digitado é: %d\n", cont);

    return 0;
}
