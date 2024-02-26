#include <stdlib.h>
#include <stdio.h>

int main() {

    float num;

    printf("Digite um valor: ");
    scanf("%f", &num);

    printf("O valor digitado com apenas uma casa decimal: %.1f\n", num);

    return 0;
}
