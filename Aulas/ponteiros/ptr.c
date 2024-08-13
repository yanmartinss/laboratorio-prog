// USANDO (*ptr): CONTEÚDO DO ENDEREÇO DA VARIÁVEL QUE ptr APONTA
// USANDO (ptr): O ENDEREÇO DA VARIÁVEL
// USANDO (&ptr): ENDEREÇO DO PONTEIRO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rangeSize 100

int main() {
    int totalRows, totalCols;
    int *ptr_totalRows = &totalRows;
    int *ptr_totalCols = &totalCols;

    puts("Digite o número de linhas da matriz: ");
    scanf("%d", ptr_totalRows);  
    puts("Digite o número de colunas da matriz: ");
    scanf("%d", ptr_totalCols);  

    int **matriz = (int **)malloc(*ptr_totalRows * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas da matriz.\n");
        return 1; 
    }

    for (int i = 0; i < *ptr_totalRows; i++) {
        matriz[i] = (int *)malloc(*ptr_totalCols * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para as colunas da linha %d.\n", i);
            
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);

            return 1;  
        }
    }

    srand(time(NULL));
    for (int i = 0; i < *ptr_totalRows; i++) {
        for (int j = 0; j < *ptr_totalCols; j++) {
            *(*(matriz + i) + j) = rand() % rangeSize; 
        }
    }

    printf("Matriz gerada:\n");
    for (int i = 0; i < *ptr_totalRows; i++) {
        for (int j = 0; j < *ptr_totalCols; j++) {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    for (int i = 0; i < *ptr_totalRows; i++) {
        free(matriz[i]);
    }
    free(matriz);  

    return 0;
}