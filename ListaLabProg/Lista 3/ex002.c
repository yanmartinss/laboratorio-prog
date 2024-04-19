#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main(){

    char string[SIZE], caractere;
    int contem;

    puts("Digite alguma frase: ");
    fgets(string, SIZE, stdin);

    puts("Digite um caractere: ");
    scanf("%c", &caractere);

    for (int i = 0; i < strlen(string); i++){
        if (string[i] == caractere){
            contem = 1;
            break;
        }
    }

    if (contem == 1){
        printf("O caractere %c está na string\n", caractere);
    }else {
        printf("O caractere %c não está na string\n", caractere);        
    }

    return 0;
}
