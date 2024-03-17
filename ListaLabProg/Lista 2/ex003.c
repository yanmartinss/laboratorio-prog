#include <stdio.h>

int main() {
    int num;
    float fat = 1;

    printf("Digite um número inteiro e positivo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Numero negativo inserido. Por favor, insira um número positivo.\n");
        return 1; 
    }

    for (int i = 1; i <= num; i++) {
        fat *= i;
    }

    printf("O fatorial de %d é: %.0f\n", num, fat);

    return 0;
}
