#include <stdio.h>

int main() {
    int x, y;
    int *pX = NULL, *pY = NULL;

    puts("Digite um número para X: ");
    scanf("%d", &x);
    puts("Digite um número para Y: ");
    scanf("%d", &y);

    pX = &x;
    pY = &y;

    printf("Antes da troca, X: %d, Y: %d\n", *pX, *pY);

    int temp = *pX;
    *pX = *pY;
    *pY = temp;

    printf("Depois da troca, X: %d, Y: %d", *pX, *pY);

    return 0;
}