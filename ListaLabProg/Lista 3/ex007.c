#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 3
#define RANGE_SIZE 20

int main(){

    int vetor[SIZE], soma = 0, produto = 1;
    float media, media_geometrica;

    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        vetor[i] = rand() % RANGE_SIZE;
        soma += vetor[i];
        produto *= vetor[i];
        printf("%d\n", vetor[i]);
    }

    media = (float) soma / SIZE;
    media_geometrica = pow(produto, 1.0 / SIZE);

    printf("Média Aritmética: %.1f\n", media);
    printf("Média Geométrica: %.1f", media_geometrica);

    return 0;
}