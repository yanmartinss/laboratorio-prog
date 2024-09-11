#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct Estudante {
        int nMatricula;
        char *nome;
        float mensalidade;
        char *dataBacharelado;
    };

    struct Estudante stud1;
    struct Estudante *ptr_stud1 = &stud1;

    ptr_stud1->nome = (char*) malloc(30 * sizeof(char));
    ptr_stud1->dataBacharelado = (char*) malloc(30 * sizeof(char));

    if (ptr_stud1->nome == NULL || ptr_stud1->dataBacharelado == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    puts("Matrícula do estudante:");
    scanf("%d", &ptr_stud1->nMatricula);
    getchar(); 

    puts("Digite o nome do estudante: ");
    fgets(ptr_stud1->nome, 30, stdin);
    ptr_stud1->nome[strcspn(ptr_stud1->nome, "\n")] = '\0';

    puts("Mensalidade do estudante: ");
    scanf("%f", &ptr_stud1->mensalidade);
    getchar();

    puts("Data do bacharelado do estudante: ");
    fgets(ptr_stud1->dataBacharelado, 30, stdin);
    ptr_stud1->dataBacharelado[strcspn(ptr_stud1->dataBacharelado, "\n")] = '\0';

    puts("******************* CADASTRO DE ESTUDANTE *******************");
    printf("No. de matrícula = %d\n", ptr_stud1->nMatricula);
    printf("Nome do estudante = %s\n", ptr_stud1->nome);
    printf("Valor da mensalidade = %.2f\n", ptr_stud1->mensalidade);
    printf("Data do bacharelado = %s\n", ptr_stud1->dataBacharelado);

    free(ptr_stud1->nome);
    free(ptr_stud1->dataBacharelado);

    return 0;
}