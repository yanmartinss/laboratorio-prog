#include <stdio.h>

int main() {
    int s, h, minutos, segundos_restantes;

    printf("Digite o tempo em segundos: ");
    scanf("%d", &s);

    h = s / 3600;
    segundos_restantes = s % 3600;
    minutos = segundos_restantes / 60;
    segundos_restantes %= 60;

    printf("O tempo é: %d horas, %d minutos e %d segundos.\n", h, minutos, segundos_restantes);

    return 0;
}
