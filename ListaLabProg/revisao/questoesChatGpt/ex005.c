#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro {
    char *titulo;
    char *autor;
    int status; 
};

struct Livro* criar_biblioteca(int num_livros);
void adicionar_livro(struct Livro **biblioteca, int *num_livros, struct Livro novo_livro);
void emprestar_livro(struct Livro *biblioteca, int num_livros, char *titulo);
void devolver_livro(struct Livro *biblioteca, int num_livros, char *titulo);
void listar_livros_disponiveis(struct Livro *biblioteca, int num_livros);
void buscar_livro_por_titulo(struct Livro *biblioteca, int num_livros, char *titulo);
void liberar_biblioteca(struct Livro *biblioteca, int num_livros);

int main() {
    int num_livros;
    printf("Digite o número de livros na biblioteca: ");
    scanf("%d", &num_livros);

    struct Livro *biblioteca = criar_biblioteca(num_livros);

    struct Livro novo_livro;
    novo_livro.titulo = (char*) malloc(100 * sizeof(char));
    novo_livro.autor = (char*) malloc(100 * sizeof(char));
    novo_livro.status = 0;

    printf("Adicionar novo livro:\n");
    printf("Título: ");
    scanf(" %[^\n]", novo_livro.titulo);
    printf("Autor: ");
    scanf(" %[^\n]", novo_livro.autor);

    adicionar_livro(&biblioteca, &num_livros, novo_livro);

    printf("\nListar livros disponíveis:\n");
    listar_livros_disponiveis(biblioteca, num_livros);

    char titulo[100];
    printf("\nDigite o título do livro para emprestar: ");
    scanf(" %[^\n]", titulo);
    emprestar_livro(biblioteca, num_livros, titulo);

    printf("\nListar livros disponíveis após empréstimo:\n");
    listar_livros_disponiveis(biblioteca, num_livros);

    printf("\nDigite o título do livro para devolver: ");
    scanf(" %[^\n]", titulo);
    devolver_livro(biblioteca, num_livros, titulo);

    printf("\nListar livros disponíveis após devolução:\n");
    listar_livros_disponiveis(biblioteca, num_livros);

    printf("\nDigite o título do livro para buscar: ");
    scanf(" %[^\n]", titulo);
    buscar_livro_por_titulo(biblioteca, num_livros, titulo);

    liberar_biblioteca(biblioteca, num_livros);

    return 0;
}

struct Livro* criar_biblioteca(int num_livros) {
    struct Livro *biblioteca = (struct Livro*) malloc(num_livros * sizeof(struct Livro));
    if (biblioteca == NULL) {
        printf("Erro ao alocar memória para a biblioteca.\n");
        exit(1);
    }

    for (int i = 0; i < num_livros; i++) {
        biblioteca[i].titulo = (char*) malloc(100 * sizeof(char));
        biblioteca[i].autor = (char*) malloc(100 * sizeof(char));
        printf("Livro %d\n", i + 1);
        printf("Título: ");
        scanf(" %[^\n]", biblioteca[i].titulo);
        printf("Autor: ");
        scanf(" %[^\n]", biblioteca[i].autor);
        biblioteca[i].status = 0; 
        printf("\n");
    }

    return biblioteca;
}

void adicionar_livro(struct Livro **biblioteca, int *num_livros, struct Livro novo_livro) {
    *biblioteca = (struct Livro*) realloc(*biblioteca, (*num_livros + 1) * sizeof(struct Livro));
    if (*biblioteca == NULL) {
        printf("Erro ao realocar memória para a biblioteca.\n");
        exit(1);
    }

    (*biblioteca)[*num_livros] = novo_livro;
    (*num_livros)++;
}

void emprestar_livro(struct Livro *biblioteca, int num_livros, char *titulo) {
    for (int i = 0; i < num_livros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            if (biblioteca[i].status == 0) {
                biblioteca[i].status = 1;
                printf("O livro '%s' foi emprestado.\n", titulo);
            } else {
                printf("O livro '%s' já está emprestado.\n", titulo);
            }
            return;
        }
    }
    printf("Livro com título '%s' não encontrado.\n", titulo);
}

void devolver_livro(struct Livro *biblioteca, int num_livros, char *titulo) {
    for (int i = 0; i < num_livros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            if (biblioteca[i].status == 1) {
                biblioteca[i].status = 0;
                printf("O livro '%s' foi devolvido.\n", titulo);
            } else {
                printf("O livro '%s' já está disponível.\n", titulo);
            }
            return;
        }
    }
    printf("Livro com título '%s' não encontrado.\n", titulo);
}

void listar_livros_disponiveis(struct Livro *biblioteca, int num_livros) {
    for (int i = 0; i < num_livros; i++) {
        if (biblioteca[i].status == 0) {
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n\n", biblioteca[i].autor);
        }
    }
}

void buscar_livro_por_titulo(struct Livro *biblioteca, int num_livros, char *titulo) {
    for (int i = 0; i < num_livros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            printf("Livro encontrado:\n");
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Status: %s\n", biblioteca[i].status == 0 ? "Disponível" : "Emprestado");
            return;
        }
    }
    printf("Livro com título '%s' não encontrado.\n", titulo);
}

void liberar_biblioteca(struct Livro *biblioteca, int num_livros) {
    for (int i = 0; i < num_livros; i++) {
        free(biblioteca[i].titulo);
        free(biblioteca[i].autor);
    }
    free(biblioteca);
}