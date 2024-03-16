#include <stdio.h>

int main(){

    int n1, n2;

    printf("Digite um número inteiro (0 para parar): ");
    scanf("%d", &n1);
    if (n1 == 0){
        printf("Programa encerrado");
        return 0;
    } else {
        while (1){
            printf("Digite outro número inteiro (0 para parar): ");
            scanf("%d", &n2);
            if (n2 > n1 && n2 > 0){
                printf("%d é maior que %d\n", n2, n1);
            } else if (n1 > n2 && n2 != 0) {
                printf("%d é menor que %d\n", n2, n1);
            } else if (n2 == 0){
                break;
            }
        }
    }
    printf("Programa encerrado\n");

    return 0;
    }
