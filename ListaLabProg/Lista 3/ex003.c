#include <stdio.h>
#include <string.h>
#define SIZE 100

int main() {
    char string[SIZE];
    int cont = 0;

    puts("Digite uma string: ");
    fgets(string, SIZE, stdin);

    while (string[cont] != '\0') {
        cont++;
    }

    printf("A quantidade de caracteres na string fornecida é: %d\n", cont);

    return 0;
}
