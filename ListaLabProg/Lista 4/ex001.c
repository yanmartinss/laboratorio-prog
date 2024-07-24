#include <stdio.h>

int main() {
    int x, y, soma;
    int *pX = NULL, *pY = NULL, *pSoma = NULL;

    puts("Digite um número para X: ");
    scanf("%d", &x);
    puts("Digite um número para Y: ");
    scanf("%d", &y);
    soma = x + y;

    pX = &x;
    pY = &y;
    pSoma = &soma;

    printf("Valor da soma dos dois números: %d\n", *pSoma);
    printf("Endereço onde a soma está armazenada: %p\n", pSoma);

    return 0;
}