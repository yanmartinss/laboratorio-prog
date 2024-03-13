#include <stdio.h>

int main(){

    float raio, diametro, circuferencia, area;

    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    diametro = 2 * raio;
    circuferencia = 2 * 3.14159 * raio;
    area = 3.14159 * (raio * raio);

    printf("O diâmetro do círculo é %.2f\n", diametro);
    printf("A tamanho da circuferência do círculo é %.2f\n", circuferencia);
    printf("O valor da área do círculo é %.2f\n", area);

    return 0;
}
