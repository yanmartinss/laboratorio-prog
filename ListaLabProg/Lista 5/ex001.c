#include <stdio.h>
#include <stdlib.h>

void somar(float *a, float *b, float *resultado) {
    *resultado = *a + *b;
}

void multiplicar(float *a, float *b, float *resultado) {
    *resultado = *a * *b;
}

void processarOperacao(char codigo, float *a, float *b, float *resultado) {
    if (codigo == 's') {
        somar(a, b, resultado);
    } else if (codigo == 'm') {
        multiplicar(a, b, resultado);
    } else {
        printf("Código de operação inválido.\n");
        exit(1);
    }
}

int main() {
    float *a = (float *)malloc(sizeof(float));
    float *b = (float *)malloc(sizeof(float));
    float *resultado = (float *)malloc(sizeof(float));
    char codigo;

    if (a == NULL || b == NULL || resultado == NULL) {
        puts("Erro na alocação de memória.\n");
        return 1;
    }

    puts("Digite o primeiro valor: ");
    scanf("%f", a);
    puts("Digite o segundo valor: ");
    scanf("%f", b);
    puts("Digite o código de operação ('s' para soma, 'm' para multiplicação): ");
    scanf(" %c", &codigo);

    processarOperacao(codigo, a, b, resultado);

    printf("O resultado da operação é: %.2f\n", *resultado);

    free(a);
    free(b);
    free(resultado);

    return 0;
}