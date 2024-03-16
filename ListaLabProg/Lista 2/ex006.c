#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    int voto, paulo = 0, renata = 0, branco = 0, nulo = 0, total = 0;

    while (1){
        printf("--------------------------------\n");
        printf("ELEIÇÕES PRESIDENCIAIS\n");
        printf("VOTE NO SEU CANDIDATO!\n");
        printf("\n");
        printf("DIGITE [0] PARA VOTAR BRANCO\n");
        printf("DIGITE [5]  PARA VOTAR NO PAULO\n");
        printf("DIGITE [7] PARA VOTAR NA RENATA\n");
        printf("DIGITE UM NÚMERO NEGATIVO PARA ENCERRAR\n");
        printf("--------------------------------\n");

        scanf("%d", &voto);

        if (voto >= 0){
            total += 1;
        }
        if (voto == 0){
            branco += 1;
        } else if (voto == 5){
            paulo += 1;
        } else if (voto == 7){
            renata += 1;
        } else if (voto > 0 && voto != 5 && voto !=7){
            nulo += 1;
        }else {
            printf("--------------------------------\n");
            printf("Votação encerrada!\n");
            break;
        }

    sleep(0.8);
    system("cls");

    }

    printf("RESULTADO DA VOTAÇÃO\n");
    printf("--------------------------------\n");
    printf("Porcentagem do candidato Paulo: %.2f%%\n", ((float)paulo / total) * 100);
    printf("Porcentagem da candidata Renata: %.2f%%\n", ((float)renata / total) * 100);
    printf("%d votos em branco\n", branco);
    printf("%d votos nulos\n", nulo);
    printf("\n");

    if (paulo > renata){
        printf("O candidato que venceu foi Paulo com mais votos que Renata\n", ((float)paulo / total) * 100);
    }else if (renata > paulo) {
        printf("A candidata que venceu foi Renata com mais votos que Paulo\n", ((float)renata / total) * 100);
    } else{
        printf("O resultado da votação foi empate\n");
    }

    return 0;
}
