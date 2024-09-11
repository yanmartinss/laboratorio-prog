#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char *nomeProduto;
    float precoProduto;
    int idProduto;
};

void adicionarProduto(struct Produto *produto);
void exibirProduto(const struct Produto *produto);
void liberarProdutos(struct Produto *produtos, int numProdutos);

int main() {
    int numProdutos;
    struct Produto *produtos;

    puts("Digite o número de produtos a serem cadastrados: ");
    scanf("%d", &numProdutos);
    getchar();

    produtos = (struct Produto*) malloc(numProdutos * sizeof(struct Produto));
    if (produtos == NULL) {
        puts("Erro ao alocar memória.");
        exit(1);
    }

    struct Produto *ptr_produto = produtos;
    for (int i = 0; i < numProdutos; i++) {
        puts("Digite as informações do produto:");
        adicionarProduto(ptr_produto);
        ptr_produto++;
    }

    puts("********** INFOS DOS PRODUTOS **********");
    ptr_produto = produtos;
    for (int i = 0; i < numProdutos; i++) {
        exibirProduto(ptr_produto);
        ptr_produto++;
    }

    liberarProdutos(produtos, numProdutos);

    return 0;
}

void adicionarProduto(struct Produto *produto) {
    produto->nomeProduto = (char*) malloc(30 * sizeof(char));
    if (produto->nomeProduto == NULL) {
        puts("Erro ao alocar memória");
        exit(2);
    }

    puts("Digite o nome do produto: ");
    fgets(produto->nomeProduto, 30, stdin);
    produto->nomeProduto[strcspn(produto->nomeProduto, "\n")] = '\0'; 

    puts("Digite o preço do produto: ");
    scanf("%f", &produto->precoProduto);

    puts("Digite o ID do produto: ");
    scanf("%d", &produto->idProduto);
    getchar(); 
}

void exibirProduto(const struct Produto *produto) {
    printf("Nome do produto: %s\n", produto->nomeProduto);
    printf("Preço do produto: %.2f\n", produto->precoProduto);
    printf("ID do produto: %d\n\n", produto->idProduto);
}

void liberarProdutos(struct Produto *produtos, int numProdutos) {
    struct Produto *ptr_produto = produtos;
    for (int i = 0; i < numProdutos; i++) {
        free(ptr_produto->nomeProduto);
        ptr_produto++;
    }
    free(produtos);
}