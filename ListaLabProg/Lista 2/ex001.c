#include <stdio.h>

int main(){
    int dia;

    while (1){
        printf("Digite um número de 1 a 7 (0 para sair): ");
        scanf("%d", &dia);
        if (dia==1){
            printf("Domingo\n");
        }else if (dia==2){
            printf("Segunda-Feira\n");
        }else if (dia==3){
            printf("Terça-Feira\n");
        }else if (dia==4){
            printf("Quarta-Feira\n");
        }else if (dia==5){
            printf("Quinta-Feira\n");
        }else if (dia==6){
            printf("Sexta-Feira\n");
        }else if (dia==7){
            printf("Sábado\n");
        }else if (dia==0){
            break;
        }else {
            printf("Dia inválido\n");
        }
    }

    return 0;
}
