#include <stdio.h>

int main(){

    int num1, num2, soma = 0, total = 0;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    for (int i = num1; i <= num2; i++){
        total += 1;
        soma += i;
    }

    printf("Média: %.1f", (float) soma / total);

    return 0;
}
