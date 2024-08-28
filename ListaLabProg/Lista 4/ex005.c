#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sizeMax 100

int encontrarTamanho(char *str) {
    int tamanho = 0;
    
    while (*str != '\0') {
        tamanho++;
        str++;
    }

    return tamanho;
}

int main() {
    char *str = NULL; 
    size_t tamanho_max = sizeMax; 
    size_t tamanho_atual;
    
    str = (char*)malloc(tamanho_max * sizeof(char));

    if (str == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite uma string: ");
    fgets(str, tamanho_max, stdin);

    tamanho_atual = encontrarTamanho(str);
    if (str[tamanho_atual] == '\n') {
        str[tamanho_atual] = '\0';
    }

    int tamanho = encontrarTamanho(str);

    printf("O tamanho da string fornecida é: %d\n", tamanho);

    free(str);

    return 0;
}
