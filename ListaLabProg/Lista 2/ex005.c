#include <stdio.h>

int main(){

    int n1, n2;

    printf("Digite um valor (0 para parar): ");
    scanf("%d", &n1);
    if (n1 == 0){
        printf("Programa encerrado");
        return 0;
    } else {
        while (1){
            printf("Digite outro valor: ");
            scanf("%d", n2);
            if (n2 > n1 && n2 > 0){
                printf("Número maior\n");
            } else if (n1 > n2 && n2 != 0) {
                printf("Número menor\n");
            } else if (n2 == 0){
                break;
            }
        }
    }
    printf("Programa encerrado\n");

    return 0;
    }
