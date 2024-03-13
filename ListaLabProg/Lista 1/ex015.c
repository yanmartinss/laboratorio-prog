#include <stdio.h>

int main() {
    int dias;
    float salbruto, saliq, imprenda;
    float gratificacao = 0.0;

    printf("Digite o número de dias trabalhados pelo vendedor: ");
    scanf("%d", &dias);

    salbruto = 50.25 * dias;

    if (dias > 10 && dias <= 20) {
        gratificacao = salbruto * 0.20;
    } else if (dias > 20) {
        gratificacao = salbruto * 0.30;
    }

    imprenda = (salbruto + gratificacao) * 0.10;

    saliq = salbruto + gratificacao - imprenda;

    printf("O salário líquido a ser pago ao vendedor é: R$%.2f\n", saliq);

    return 0;
}
