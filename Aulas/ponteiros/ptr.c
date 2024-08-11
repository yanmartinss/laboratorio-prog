// USANDO (*ptr): CONTEÚDO DO ENDEREÇO DA VARIÁVEL QUE ptr APONTA
// USANDO (ptr): O ENDEREÇO DA VARIÁVEL
// USANDO (&ptr): ENDEREÇO DO PONTEIRO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size 5

int main() {
    float vetor[size];
    float *ptr_vetor = vetor;

    puts("Digite os valores para o vetor: ");

    for(int i = 0; i < size; i++) {
        scanf("%f", ptr_vetor + i);
    }

    puts("Endereco da posicao de cada valor do vetor: \n");
    for (int i = 0; i < size; i++) {
        printf("%p\n", ptr_vetor + i);
    }

    return 0;
}