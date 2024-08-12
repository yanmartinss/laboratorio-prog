#include <stdio.h>

float calculator(float n1, float n2, int op) {
    switch(op) {
        case 1:
            return n1 + n2;
        case 2:
            return n1 - n2;
        case 3:
            return n1 * n2;
        case 4:
            if (n2 != 0) {
                return n1 / n2;
            } else {
                puts("Erro: Divisão por zero!");
                exit(1);
            }
    }
}

int main() {
    float n1, n2;
    int op;

    puts("Qual operação você quer executar? ");
    while (1) {
        puts("[1] SOMA\n[2] SUBTRAÇÃO\n[3] MULTIPLICAÇÃO\n[4] DIVISÃO");
        scanf("%d", &op);
        if (op == 1 || op == 2 || op == 3 || op == 4) {
            break;
        } else {
            puts("Digite um número válido");
        }
    }
    
    puts("Digite um número: ");
    scanf("%f", &n1);

    puts("Digite outro número: ");
    scanf("%f", &n2);

    float result = calculator(n1, n2, op);

    printf("Resultado: %.*f\n", (op == 4) ? 2 : 0, result);


    return 0;
}
