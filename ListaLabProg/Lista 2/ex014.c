#include <stdio.h>

int main() {
    int a, b, cont = 0, temp;

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
        if (i % 3 == 0) {
            cont++;
        }
    }

    printf("A quantidade de números divisíveis por 3 de %d a %d é: %d\n", a, b, cont);

    return 0;
}
