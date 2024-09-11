#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char *nome;
    int id;
    int quantidade;
    float preco;
};

struct Produto* criar_produtos(int num_produtos);
void adicionar_produto(struct Produto **produtos, int *num_produtos, struct Produto novo_produto);
void remover_produto(struct Produto **produtos, int *num_produtos, int id);
void atualizar_produto(struct Produto *produtos, int num_produtos, int id, int nova_quantidade, float novo_preco);
void listar_produtos(struct Produto *produtos, int num_produtos);
void liberar_produtos(struct Produto *produtos, int num_produtos);

int main() {
    int num_produtos;
    puts("Digite o número de produtos no estoque: ");
    scanf("%d", &num_produtos);

    struct Produto *produtos = criar_produtos(num_produtos);

    struct Produto novo_produto;
    novo_produto.nome = (char*) malloc(100 * sizeof(char));
    puts("Adicionar novo produto:\n");
    puts("Nome: ");
    scanf(" %[^\n]", novo_produto.nome);
    puts("ID: ");
    scanf("%d", &novo_produto.id);
    puts("Quantidade: ");
    scanf("%d", &novo_produto.quantidade);
    puts("Preço: ");
    scanf("%f", &novo_produto.preco);

    adicionar_produto(&produtos, &num_produtos, novo_produto);

    puts("\nListar produtos:\n");
    listar_produtos(produtos, num_produtos);

    int id;
    puts("\nDigite o ID do produto para atualizar: ");
    scanf("%d", &id);
    int nova_quantidade;
    float novo_preco;
    puts("Nova quantidade: ");
    scanf("%d", &nova_quantidade);
    puts("Novo preço: ");
    scanf("%f", &novo_preco);

    atualizar_produto(produtos, num_produtos, id, nova_quantidade, novo_preco);

    puts("\nListar produtos após atualização:\n");
    listar_produtos(produtos, num_produtos);

    puts("\nDigite o ID do produto para remover: ");
    scanf("%d", &id);
    remover_produto(&produtos, &num_produtos, id);

    puts("\nListar produtos após remoção:\n");
    listar_produtos(produtos, num_produtos);

    liberar_produtos(produtos, num_produtos);

    return 0;
}

struct Produto* criar_produtos(int num_produtos) {
    struct Produto *produtos = (struct Produto*) malloc(num_produtos * sizeof(struct Produto));
    if (produtos == NULL) {
        puts("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < num_produtos; i++) {
        produtos[i].nome = (char*) malloc(100 * sizeof(char)); 
        printf("Produto %d\n", i + 1);
        puts("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        puts("ID: ");
        scanf("%d", &produtos[i].id);
        puts("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
        puts("Preço: ");
        scanf("%f", &produtos[i].preco);
        puts("\n");
    }

    return produtos;
}

void adicionar_produto(struct Produto **produtos, int *num_produtos, struct Produto novo_produto) {
    *produtos = (struct Produto*) realloc(*produtos, (*num_produtos + 1) * sizeof(struct Produto));
    if (*produtos == NULL) {
        puts("Erro ao realocar memória.\n");
        exit(1);
    }

    (*produtos)[*num_produtos] = novo_produto;
    (*num_produtos)++;
}

void remover_produto(struct Produto **produtos, int *num_produtos, int id) {
    int i;
    for (i = 0; i < *num_produtos; i++) {
        if ((*produtos)[i].id == id) {
            free((*produtos)[i].nome); 

            for (int j = i; j < *num_produtos - 1; j++) {
                (*produtos)[j] = (*produtos)[j + 1];
            }

            *produtos = (struct Produto*) realloc(*produtos, (*num_produtos - 1) * sizeof(struct Produto));
            if (*produtos == NULL && *num_produtos > 1) {
                puts("Erro ao realocar memória.\n");
                exit(1);
            }

            (*num_produtos)--;
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void atualizar_produto(struct Produto *produtos, int num_produtos, int id, int nova_quantidade, float novo_preco) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].id == id) {
            produtos[i].quantidade = nova_quantidade;
            produtos[i].preco = novo_preco;
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void listar_produtos(struct Produto *produtos, int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("ID: %d\n", produtos[i].id);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preço: %.2f\n\n", produtos[i].preco);
    }
}

void liberar_produtos(struct Produto *produtos, int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        free(produtos[i].nome);  
    }
    free(produtos); 
}