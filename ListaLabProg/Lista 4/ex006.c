#include <stdio.h>

int main() {
    char source[100], destination[100];
    char *ptrSource = source;
    char *ptrDestination = destination;

    puts("Digite a string de origem: ");
    fgets(source, sizeof(source), stdin);

    while (*ptrSource != '\0') {
        if (*ptrSource == '\n') {
            *ptrSource = '\0';
        }
        ptrSource++;
    }

    ptrSource = source;

    while (*ptrSource != '\0') {
        *ptrDestination = *ptrSource;
        ptrSource++;
        ptrDestination++;
    }
    *ptrDestination = '\0';

    printf("A string copiada é: %s\n", destination);

    return 0;
}