#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudante* adicionar_estudantes(int num_estudantes);
void imprimir_estudantes(struct Estudante *estudantes, int num_estudantes);
void buscar_por_matricula(struct Estudante *estudantes, int num_estudantes, int matricula);

struct Estudante {
    char *nome;
    int idade;
    int matricula;
};

int main() {
    int num_estudantes;
    puts("Digite o número de estudantes a serem cadastrados: ");
    scanf("%d", &num_estudantes);

    struct Estudante *estudantes = adicionar_estudantes(num_estudantes);

    imprimir_estudantes(estudantes, num_estudantes);

    int matricula;
    puts("Digite a matrícula do estudante a ser buscado: ");
    scanf("%d", &matricula);
    buscar_por_matricula(estudantes, num_estudantes, matricula);

    for (int i = 0; i < num_estudantes; i++) {
        free(estudantes[i].nome); 
    }
    free(estudantes); 

    return 0;
}

struct Estudante* adicionar_estudantes(int num_estudantes) {
    struct Estudante *estudantes = (struct Estudante*) malloc(num_estudantes * sizeof(struct Estudante));
    if (estudantes == NULL) {
        puts("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < num_estudantes; i++) {
        estudantes[i].nome = (char*) malloc(100 * sizeof(char));
        printf("Estudante %d\n", i + 1);
        puts("Nome: ");
        scanf(" %[^\n]", estudantes[i].nome);
        puts("Idade: ");
        scanf("%d", &estudantes[i].idade);
        puts("Número de matrícula: ");
        scanf("%d", &estudantes[i].matricula);
        printf("\n");
    }

    return estudantes;
}

void imprimir_estudantes(struct Estudante *estudantes, int num_estudantes) {
    puts("Lista de estudantes cadastrados:\n");
    for (int i = 0; i < num_estudantes; i++) {
        puts("Estudante %d:\n", i + 1);
        printf("Nome: %s\n", estudantes[i].nome);
        printf("Idade: %d\n", estudantes[i].idade);
        printf("Matrícula: %d\n\n", estudantes[i].matricula);
    }
}

void buscar_por_matricula(struct Estudante *estudantes, int num_estudantes, int matricula) {
    for (int i = 0; i < num_estudantes; i++) {
        if (estudantes[i].matricula == matricula) {
            puts("Estudante encontrado:\n");
            printf("Nome: %s\n", estudantes[i].nome);
            printf("Idade: %d\n", estudantes[i].idade);
            printf("Matrícula: %d\n", estudantes[i].matricula);
            return;
        }
    }
    printf("Nenhum estudante encontrado com a matrícula %d.\n", matricula);
}