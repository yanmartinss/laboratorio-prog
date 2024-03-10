#include <stdio.h>

int main() {
    int horas, minutos, segundos, total;

    printf("Digite as horas: ");
    scanf("%d", &horas);

    printf("Digite os minutos: ");
    scanf("%d", &minutos);

    printf("Digite os segundos: ");
    scanf("%d", &segundos);

    total = horas * 3600 + minutos * 60 + segundos;

    printf("O total de segundos é: %d\n", total);
    
    return 0;
}
