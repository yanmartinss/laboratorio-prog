#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contato {
    char *nome;
    char *telefone;
    char *endereco;
};

struct Contato* criar_agenda(int num_contatos);
void adicionar_contato(struct Contato **agenda, int *num_contatos, struct Contato novo_contato);
void remover_contato(struct Contato **agenda, int *num_contatos, char *nome);
void atualizar_contato(struct Contato *agenda, int num_contatos, char *nome);
void buscar_por_nome(struct Contato *agenda, int num_contatos, char *nome);
void listar_contatos(struct Contato *agenda, int num_contatos);
void liberar_agenda(struct Contato *agenda, int num_contatos);

int main() {
    int num_contatos;
    printf("Digite o número de contatos na agenda: ");
    scanf("%d", &num_contatos);

    struct Contato *agenda = criar_agenda(num_contatos);

    struct Contato novo_contato;
    novo_contato.nome = (char*) malloc(100 * sizeof(char));
    novo_contato.telefone = (char*) malloc(20 * sizeof(char));
    novo_contato.endereco = (char*) malloc(200 * sizeof(char));

    printf("Adicionar novo contato:\n");
    printf("Nome: ");
    scanf(" %[^\n]", novo_contato.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", novo_contato.telefone);
    printf("Endereço: ");
    scanf(" %[^\n]", novo_contato.endereco);

    adicionar_contato(&agenda, &num_contatos, novo_contato);

    printf("\nListar contatos:\n");
    listar_contatos(agenda, num_contatos);

    char nome[100];
    printf("\nDigite o nome do contato para buscar: ");
    scanf(" %[^\n]", nome);
    buscar_por_nome(agenda, num_contatos, nome);

    printf("\nDigite o nome do contato para atualizar: ");
    scanf(" %[^\n]", nome);
    atualizar_contato(agenda, num_contatos, nome);

    printf("\nListar contatos após atualização:\n");
    listar_contatos(agenda, num_contatos);

    printf("\nDigite o nome do contato para remover: ");
    scanf(" %[^\n]", nome);
    remover_contato(&agenda, &num_contatos, nome);

    printf("\nListar contatos após remoção:\n");
    listar_contatos(agenda, num_contatos);

    liberar_agenda(agenda, num_contatos);

    return 0;
}

struct Contato* criar_agenda(int num_contatos) {
    struct Contato *agenda = (struct Contato*) malloc(num_contatos * sizeof(struct Contato));
    if (agenda == NULL) {
        printf("Erro ao alocar memória para a agenda.\n");
        exit(1);
    }

    for (int i = 0; i < num_contatos; i++) {
        agenda[i].nome = (char*) malloc(100 * sizeof(char));
        agenda[i].telefone = (char*) malloc(20 * sizeof(char));
        agenda[i].endereco = (char*) malloc(200 * sizeof(char));
        printf("Contato %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", agenda[i].nome);
        printf("Telefone: ");
        scanf(" %[^\n]", agenda[i].telefone);
        printf("Endereço: ");
        scanf(" %[^\n]", agenda[i].endereco);
        printf("\n");
    }

    return agenda;
}

void adicionar_contato(struct Contato **agenda, int *num_contatos, struct Contato novo_contato) {
    *agenda = (struct Contato*) realloc(*agenda, (*num_contatos + 1) * sizeof(struct Contato));
    if (*agenda == NULL) {
        printf("Erro ao realocar memória para a agenda.\n");
        exit(1);
    }

    (*agenda)[*num_contatos] = novo_contato;
    (*num_contatos)++;
}

void remover_contato(struct Contato **agenda, int *num_contatos, char *nome) {
    int i;
    for (i = 0; i < *num_contatos; i++) {
        if (strcmp((*agenda)[i].nome, nome) == 0) {
            free((*agenda)[i].nome);
            free((*agenda)[i].telefone);
            free((*agenda)[i].endereco);

            for (int j = i; j < *num_contatos - 1; j++) {
                (*agenda)[j] = (*agenda)[j + 1];
            }

            *agenda = (struct Contato*) realloc(*agenda, (*num_contatos - 1) * sizeof(struct Contato));
            if (*agenda == NULL && *num_contatos > 1) {
                printf("Erro ao realocar memória para a agenda.\n");
                exit(1);
            }

            (*num_contatos)--;
            return;
        }
    }
    printf("Contato com nome %s não encontrado.\n", nome);
}

void atualizar_contato(struct Contato *agenda, int num_contatos, char *nome) {
    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Atualizar informações do contato %s:\n", nome);
            printf("Novo nome: ");
            scanf(" %[^\n]", agenda[i].nome);
            printf("Novo telefone: ");
            scanf(" %[^\n]", agenda[i].telefone);
            printf("Novo endereço: ");
            scanf(" %[^\n]", agenda[i].endereco);
            return;
        }
    }
    printf("Contato com nome %s não encontrado.\n", nome);
}

void buscar_por_nome(struct Contato *agenda, int num_contatos, char *nome) {
    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Endereço: %s\n", agenda[i].endereco);
            return;
        }
    }
    printf("Contato com nome %s não encontrado.\n", nome);
}

void listar_contatos(struct Contato *agenda, int num_contatos) {
    for (int i = 0; i < num_contatos; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Endereço: %s\n\n", agenda[i].endereco);
    }
}

void liberar_agenda(struct Contato *agenda, int num_contatos) {
    for (int i = 0; i < num_contatos; i++) {
        free(agenda[i].nome);
        free(agenda[i].telefone);
        free(agenda[i].endereco);
    }
    free(agenda);
}