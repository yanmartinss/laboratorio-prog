#include <stdio.h>

int main() {
    int x, c, d, u, y;

    printf("Digite um número de três dígitos: ");
    scanf("%d", &x);

    c = x / 100;
    d = (x / 10) % 10;
    u = x % 10;

    y = u * 100 + d * 10 + c;

    printf("O número com os dígitos na ordem inversa é: %d\n", y);

    return 0;
}
