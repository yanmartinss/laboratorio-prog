#include <stdio.h>

int main(){

    int num1, num2, temp;

    printf("Digite o primeiro valor: ");
    scanf("%d", &num1);

    printf("Digite o segundo valor: ");
    scanf("%d", &num2);

    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("Valores após a troca: \n");
    printf("A: %d\n", num1);
    printf("B: %d\n", num2);


    return 0;
}
