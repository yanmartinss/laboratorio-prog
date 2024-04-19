#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

int main() {
    int vetor[SIZE];
    int menor, maior, cont = 0;

    for(int i = 0; i < SIZE; i++) {
        puts("Digite um número: ");
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < SIZE; i++){
        cont += 1;
        if (cont == 1){
            menor = vetor[i];
            maior = vetor[i];
        }else{
            if (vetor[i] > maior){
                maior = vetor[i];
            }if (vetor[i] < menor) {
                menor = vetor[i];
            }
        }
    }

    printf("A soma do menor e do maior elemento do vetor fornecido é: %d\n", maior + menor);

    return 0;
}