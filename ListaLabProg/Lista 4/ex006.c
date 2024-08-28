#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 100

void copiarString(const char *origem, char *destino) {
    while (*origem != '\0') {  
        *destino = *origem; 
        origem++;        
        destino++;     
    }
    *destino = '\0';        
}

int main() {
    char *origem = NULL, *destino = NULL;
    size_t tamanho_max = maxSize;  

    origem = (char*)malloc(tamanho_max * sizeof(char));
    if (origem == NULL) {
        puts("Erro de alocação de memória para origem!\n");
        return 1;
    }

    destino = (char*)malloc(tamanho_max * sizeof(char));
    if (destino == NULL) {
        puts("Erro de alocação de memória para destino!\n");
        free(origem);
        return 1;
    }

    puts("Digite uma string: ");
    fgets(origem, tamanho_max, stdin);

    size_t tamanho = 0;
    while (origem[tamanho] != '\0') {
        if (origem[tamanho] == '\n') {
            origem[tamanho] = '\0';
            break;
        }
        tamanho++;
    }

    copiarString(origem, destino);

    printf("String copiada: %s\n", destino);

    free(origem);
    free(destino);

    return 0;
}