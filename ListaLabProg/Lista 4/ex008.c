#include <stdio.h>
#include <string.h>

#define size 100

int main() {
    char str[size], ch;
    char *ptrStr = str;

    puts("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    puts("Digite o caractere que deseja buscar: ");
    scanf("%c", &ch);

    int found = 0;

    while (*ptrStr != '\0') {
        if (*ptrStr == ch) {
            found = 1;
            break;
        }
        ptrStr++;
    }

    printf(found ? "Caractere '%c' encontrado na posicao %ld da string.\n" : "Caractere '%c' nao encontrado na string.\n", ch, found ? ptrStr - str : 0);

    return 0;
}