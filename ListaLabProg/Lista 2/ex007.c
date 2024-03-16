#include <stdio.h>

int main(){

    int n1, n2 = 0;

    printf("Digite o valor do primeiro número: ");
    scanf("%d", &n1);
    while (n2 == 0 ){
        printf("Digite o valor do segundo número: ");
        scanf("%d", &n2);
    }
    printf("O resultado da divisão entre %d e %d é igual a %.1f", n1, n2, (float) n1 / n2);
    return 0;
}
