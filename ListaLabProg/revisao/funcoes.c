#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float calcularAreaRetang(float x, float y);
    float x = 10, y = 20;

    printf("%.1f", calcularAreaRetang(x, y));

    return 0;
}

float calcularAreaRetang(float base, float altura) {
    return base * altura;
}