#include <stdio.h>

int main() {
    int termos, sinal = 1, divisor = 1;
    double pi = 0;

    printf("Termos   Valor Aproximado de Pi\n");

    for (termos = 1; termos <= 50; termos++) {
        pi += sinal * 4.0 / divisor;
        printf("%4d          %.5f\n", termos, pi);
        sinal = -sinal;
        divisor += 2;
    }

    return 0;
}
