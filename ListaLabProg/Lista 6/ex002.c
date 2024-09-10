#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estoque {
    char nomePeca[100];
    int numeroPeca;
    float preco;
    int numeroPedido;
};

void preencherEstoque(struct Estoque *item) {
    puts("Digite o nome da peça: ");
    fgets(item -> nomePeca, sizeof(item -> nomePeca), stdin);
    item -> nomePeca[strcspn(item -> nomePeca, "\n")] = 0;

    puts("Digite o número da peça: ");
    scanf("%d", &(item -> numeroPeca));

    puts("Digite o preço da peça: ");
    scanf("%f", &(item -> preco));

    puts("Digite o número do pedido: ");
    scanf("%d", &(item -> numeroPedido));
}

void exibirEstoque(struct Estoque *item) {
    puts("\nInformações da Peça:\n");
    printf("Nome da peça: %s\n", item -> nomePeca);
    printf("Número da peça: %d\n", item -> numeroPeca);
    printf("Preço da peça: %.2f\n", item -> preco);
    printf("Número do pedido: %d\n", item -> numeroPedido);
}

int main() {
    struct Estoque *item = (struct Estoque*) malloc(sizeof(struct Estoque));

    preencherEstoque(item);

    exibirEstoque(item);

    free(item);

    return 0;
}