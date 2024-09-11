#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudante {
    char *nome;
    float nota;
};

struct Turma {
    char *nome;
    struct Estudante *estudantes;
    int num_estudantes;
};

struct Turma* criar_turmas(int num_turmas);
void adicionar_estudantes(struct Turma *turmas, int num_turmas);
float calcular_media(struct Estudante *estudantes, int num_estudantes);
void imprimir_dados(struct Turma *turmas, int num_turmas);
void liberar_turmas(struct Turma *turmas, int num_turmas);

int main() {
    int num_turmas;
    printf("Digite o número de turmas: ");
    scanf("%d", &num_turmas);

    struct Turma *turmas = criar_turmas(num_turmas);

    adicionar_estudantes(turmas, num_turmas);

    imprimir_dados(turmas, num_turmas);

    liberar_turmas(turmas, num_turmas);

    return 0;
}

struct Turma* criar_turmas(int num_turmas) {
    struct Turma *turmas = (struct Turma*) malloc(num_turmas * sizeof(struct Turma));
    if (turmas == NULL) {
        printf("Erro ao alocar memória para turmas.\n");
        exit(1);
    }

    for (int i = 0; i < num_turmas; i++) {
        turmas[i].nome = (char*) malloc(100 * sizeof(char));
        printf("Digite o nome da turma %d: ", i + 1);
        scanf(" %[^\n]", turmas[i].nome);
        turmas[i].num_estudantes = 0;
        turmas[i].estudantes = NULL;
    }

    return turmas;
}

void adicionar_estudantes(struct Turma *turmas, int num_turmas) {
    for (int i = 0; i < num_turmas; i++) {
        int num_estudantes;
        printf("Digite o número de estudantes para a turma %s: ", turmas[i].nome);
        scanf("%d", &num_estudantes);

        turmas[i].estudantes = (struct Estudante*) malloc(num_estudantes * sizeof(struct Estudante));
        if (turmas[i].estudantes == NULL) {
            printf("Erro ao alocar memória para estudantes.\n");
            exit(1);
        }

        turmas[i].num_estudantes = num_estudantes;
        for (int j = 0; j < num_estudantes; j++) {
            turmas[i].estudantes[j].nome = (char*) malloc(100 * sizeof(char));
            printf("Digite o nome do estudante %d da turma %s: ", j + 1, turmas[i].nome);
            scanf(" %[^\n]", turmas[i].estudantes[j].nome);
            printf("Digite a nota do estudante %d da turma %s: ", j + 1, turmas[i].nome);
            scanf("%f", &turmas[i].estudantes[j].nota);
        }
    }
}

float calcular_media(struct Estudante *estudantes, int num_estudantes) {
    float soma = 0.0;
    for (int i = 0; i < num_estudantes; i++) {
        soma += estudantes[i].nota;
    }
    return (num_estudantes > 0) ? (soma / num_estudantes) : 0.0;
}

void imprimir_dados(struct Turma *turmas, int num_turmas) {
    for (int i = 0; i < num_turmas; i++) {
        printf("\nTurma %s:\n", turmas[i].nome);
        for (int j = 0; j < turmas[i].num_estudantes; j++) {
            printf("Estudante %d: Nome: %s, Nota: %.2f\n", j + 1, turmas[i].estudantes[j].nome, turmas[i].estudantes[j].nota);
        }
        float media = calcular_media(turmas[i].estudantes, turmas[i].num_estudantes);
        printf("Média da turma: %.2f\n", media);
    }
}

void liberar_turmas(struct Turma *turmas, int num_turmas) {
    for (int i = 0; i < num_turmas; i++) {
        for (int j = 0; j < turmas[i].num_estudantes; j++) {
            free(turmas[i].estudantes[j].nome); 
        }
        free(turmas[i].estudantes); 
        free(turmas[i].nome);
    }
    free(turmas);
}