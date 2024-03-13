#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, num3;
    double media_aritmetica, media_geometrica;

    printf("Digite o primeiro número em ponto flutuante: ");
    scanf("%lf", &num1);

    printf("Digite o segundo número em ponto flutuante: ");
    scanf("%lf", &num2);

    printf("Digite o terceiro número em ponto flutuante: ");
    scanf("%lf", &num3);

    media_aritmetica = (num1 + num2 + num3) / 3;

    media_geometrica = pow(num1 * num2 * num3, 1.0 / 3);

    printf("A média aritmética dos três números é: %.2f\n", media_aritmetica);
    printf("A média geométrica dos três números é: %.2f\n", media_geometrica);

    return 0;
}
