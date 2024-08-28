#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

char* buscarCaractere(const char *str, char caractere) {
    while (*str != '\0') {  
        if (*str == caractere) { 
            return (char*)str; 
        }
        str++;   
    }
    return NULL; 
}

int main() {
    char *str = NULL;
    size_t tamanho_max = maxSize;  

    str = (char*)malloc(tamanho_max * sizeof(char));
    if (str == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite uma string: ");
    fgets(str, tamanho_max, stdin);

    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr == '\n') {
            *ptr = '\0';
            break;
        }
        ptr++;
    }

    char caractere;
    printf("Digite o caractere a ser buscado: ");
    scanf(" %c", &caractere); 

    char *resultado = buscarCaractere(str, caractere);

    if (resultado != NULL) {
        printf("Caractere '%c' encontrado na posição: %ld\n", caractere, resultado - str);
    } else {
        printf("Caractere '%c' não encontrado na string.\n", caractere);
    }

    free(str);

    return 0;
}