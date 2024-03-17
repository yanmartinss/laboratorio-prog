#include <stdio.h>

int main() {
    int a, b, soma = 0, temp;

    printf("Digite o primeiro número: ");
    scanf("%d", &a);

    printf("Digite o segundo número: ");
    scanf("%d", &b);

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            soma += i;
        }
    }

    printf("A soma dos números de %d a %d é: %d\n", a, b, soma);

    return 0;
}
