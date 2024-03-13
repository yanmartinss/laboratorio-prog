#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2;
    double dist;

    printf("Digite as coordenadas (x) do primeiro ponto: ");
    scanf("%lf", &x1);
    printf("Digite as coordenadas (y) do primeiro ponto: ");
    scanf("%lf", &y1);

    printf("Digite as coordenadas (x) do segundo ponto: ");
    scanf("%lf", &x2);
    printf("Digite as coordenadas (y) do segundo ponto: ");
    scanf("%lf", &y2);

    dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("A distância entre os dois pontos é: %.2f\n", dist);

    return 0;
}
