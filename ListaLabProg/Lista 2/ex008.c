#include <stdio.h>

int main() {
    float mercadoria, entrada, prestacao;

    printf("Digite o valor da mercadoria: R$ ");
    scanf("%f", &mercadoria);

    entrada = mercadoria / 3;
    entrada = (int)entrada;
    prestacao = entrada;

    if (mercadoria - (entrada + 2 * prestacao) > 0) {
        entrada++;
    }

    printf("Valor da entrada: R$ %.2f\n", entrada);
    printf("Valor das duas prestações: R$ %.2f\n", prestacao);

    return 0;
}
