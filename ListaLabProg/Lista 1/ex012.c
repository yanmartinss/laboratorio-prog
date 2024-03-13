#include <stdio.h>

int main(){

    int num1, num2;

    printf("Digite o primeiro valor: ");
    scanf("%d", &num1);

    printf("Digite o segundo valor: ");
    scanf("%d", &num2);

    printf("\n");

    printf("A soma entre %d e %d é igual a %d\n", num1, num2, num1+num2);

    printf("O produto entre %d e %d é igual a %d\n", num1, num2, num1*num2)/

    printf("A diferença entre entre %d e %d é igual a %d\n", num1, num2, num1-num2);

    printf("O quociente da divisão entre %d e %d é %.2f\n", num1, num2, (float)num1/num2);

    printf("O resto da divisão %d e %d é %d\n", num1, num2, num1 % num2);

    return 0;
}
