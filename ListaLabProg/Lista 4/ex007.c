#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 100

char* concatenarStrings(const char *str1, const char *str2) {
    size_t tamanho_total = strlen(str1) + strlen(str2) + 1;

    char *resultado = (char*)malloc(tamanho_total * sizeof(char));

    if (resultado == NULL) { 
        puts("Erro de alocação de memória!\n");
        return NULL;
    }

    char *ptr = resultado;

    while (*str1 != '\0') {
        *ptr++ = *str1++;
    }

    while (*str2 != '\0') {
        *ptr++ = *str2++;
    }

    *ptr = '\0';

    return resultado;
}

int main() {
    char *str1 = NULL, *str2 = NULL;
    size_t tamanho_max = maxSize;

    str1 = (char*)malloc(tamanho_max * sizeof(char));
    if (str1 == NULL) {
        puts("Erro de alocação de memória para str1!\n");
        return 1;
    }

    str2 = (char*)malloc(tamanho_max * sizeof(char));
    if (str2 == NULL) {
        puts("Erro de alocação de memória para str2!\n");
        free(str1);
        return 1;
    }

    puts("Digite a primeira string: ");
    fgets(str1, tamanho_max, stdin);

    char *ptr = str1;
    while (*ptr != '\0') {
        if (*ptr == '\n') {
            *ptr = '\0';
            break;
        }
        ptr++;
    }

    puts("Digite a segunda string: ");
    fgets(str2, tamanho_max, stdin);

    ptr = str2;
    while (*ptr != '\0') {
        if (*ptr == '\n') {
            *ptr = '\0';
            break;
        }
        ptr++;
    }

    char *resultado = concatenarStrings(str1, str2);
    if (resultado != NULL) {
        printf("String concatenada: %s\n", resultado);

        free(resultado);
    }

    free(str1);
    free(str2);

    return 0;
}
