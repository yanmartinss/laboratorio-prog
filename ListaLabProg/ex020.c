#include <stdio.h>

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    (num % 2 == 0) ? printf("O número é par.\n") : printf("O número é ímpar.\n");

    return 0;
}
