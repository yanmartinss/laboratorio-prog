#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Professor {
    char nome[100];
    int idade;
    char departamento[100];
};

struct Disciplina {
    char nomeDisciplina[100];
    int codigo;
    struct Professor professor; 
};

void preencherProfessor(struct Professor *prof) {
    puts("Digite o nome do professor: ");
    fgets(prof->nome, sizeof(prof->nome), stdin);
    prof->nome[strcspn(prof->nome, "\n")] = 0; 

    puts("Digite a idade do professor: ");
    scanf("%d", &(prof -> idade));
    getchar(); 

    puts("Digite o departamento do professor: ");
    fgets(prof -> departamento, sizeof(prof -> departamento), stdin);
    prof -> departamento[strcspn(prof -> departamento, "\n")] = 0;
}

void preencherDisciplina(struct Disciplina *disc) {
    puts("\nDigite o nome da disciplina: ");
    fgets(disc -> nomeDisciplina, sizeof(disc -> nomeDisciplina), stdin);
    disc -> nomeDisciplina[strcspn(disc -> nomeDisciplina, "\n")] = 0;

    puts("Digite o código da disciplina: ");
    scanf("%d", &(disc -> codigo));
    getchar();

    puts("\n--- Dados do Professor ---\n");
    preencherProfessor(&(disc -> professor));
}

void exibirDisciplina(struct Disciplina *disc) {
    puts("\n--- Informações da Disciplina ---\n");
    printf("Nome da disciplina: %s\n", disc -> nomeDisciplina);
    printf("Código da disciplina: %d\n", disc -> codigo);

    puts("\n--- Informações do Professor ---\n");
    printf("Nome do professor: %s\n", disc -> professor.nome);
    printf("Idade do professor: %d\n", disc -> professor.idade);
    printf("Departamento: %s\n", disc -> professor.departamento);
}

int main() {
    struct Disciplina disc;

    preencherDisciplina(&disc);

    exibirDisciplina(&disc);

    return 0;
}