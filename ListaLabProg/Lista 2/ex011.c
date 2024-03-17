#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    printf("Quadrados dos números inteiros múltiplos de 4 na faixa de %d a %d:\n", a, b);

    if (a % 4 != 0) {
        a += 4 - (a % 4);
    }

    for (int num = a; num <= b; num += 4) {
        printf("%d^2 = %d\n", num, num * num);
    }

    return 0;
}
