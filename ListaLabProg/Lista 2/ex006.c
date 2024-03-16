#include <stdio.h>
#include <stdlib.h>

int main(){

    int voto, paulo = 0, renata = 0, branco = 0, nulo = 0;

    while (1){
        printf("--------------------------------\n");
        printf("ELEIÇÕES PRESIDENCIAIS\n");
        printf("VOTE NO SEU CANDIDATO!\n");
        printf("\n");
        printf("DIGITE [0] PARA VOTAR BRANCO\n");
        printf("DIGITE [5]  PARA VOTAR NO PAULO\n");
        printf("DIGITE [7] PARA VOTAR NA RENATA\n");
        printf("--------------------------------\n");
        printf("digite um número negativo para encerrar\n");
        scanf("%d", &voto);
        if (voto == 0){
            branco += 1;
        } else if (voto == 5){
            paulo += 1;
        } else if (voto == 7){
            renata += 1;
        } else if (voto >0 && voto != 5 && voto !=7){
            nulo += 1;
        }else {
            printf("Votação encerrada!\n");
            break;
        }
    sleep(2);
    system("cls");
    }

    return 0;
}
