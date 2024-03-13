#include <stdio.h>
#include <math.h>

int main() {
    int x, potencia, resultado, res2;

    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor da potência: ");
    scanf("%d", &potencia);

    resultado = (x * 2);
    res2 = pow(resultado, potencia);

    printf("O produto entre %d e 2 elevado a %d é: %d\n", x, potencia, res2);

    return 0;
}
