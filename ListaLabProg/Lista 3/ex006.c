#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){

    char str[SIZE];

    puts("Digite uma frase: ");
    fgets(str, SIZE, stdin);

    puts("String inversa: ");
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}