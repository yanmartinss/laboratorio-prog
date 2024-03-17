#include <stdio.h>

int main() {

    printf("Quadrados dos números inteiros múltiplos de 4 de 15 a 90:\n");

    for (int num = 16; num <= 90; num += 4) {
        printf("%d^2 = %d\n", num, num * num);
    }

    return 0;
}
