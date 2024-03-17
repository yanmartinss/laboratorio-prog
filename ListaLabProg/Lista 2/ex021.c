#include <stdio.h>

int main() {
    int numero, original, inverso = 0, digito;

    printf("Digite um nímero de cinco dígitos: ");
    scanf("%d", &numero);

    original = numero;

    while (numero > 0) {
        digito = numero % 10;
        inverso = inverso * 10 + digito;
        numero /= 10;
    }

    if (original == inverso) {
        printf("%d é um palíndromo.\n", original);
    } else {
        printf("%d não é um palíndromo.\n", original);
    }

    return 0;
}
