#include <stdio.h>

int main() {

    float cotacao, valor, res;

    printf("Digite a cotação do dólar hoje: ");
    scanf("%f", &cotacao);

    printf("Digite a quantidade que deseja converter: R$");
    scanf("%f", &valor);

    res = valor / cotacao;

    printf("R$%.2f vale U$%.2f\n", valor, res);

    return 0;
}
