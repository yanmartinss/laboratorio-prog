#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FERRAMENTAS 100

struct Ferramenta {
    int registro;           
    char nome[100];        
    int quantidade;         
    float custo;           
};

void inicializarArquivo() {
    FILE *arquivo = fopen("hardware.dat", "wb");

    if (arquivo == NULL) {
        puts("Erro ao criar o arquivo.\n");
        exit(1);
    }

    struct Ferramenta ferramentaVazia = {0, "", 0, 0.0};

    for (int i = 0; i < MAX_FERRAMENTAS; i++) {
        fwrite(&ferramentaVazia, sizeof(struct Ferramenta), 1, arquivo);
    }

    fclose(arquivo);
    puts("Arquivo inicializado com 100 registros vazios.\n");
}

void inserirFerramenta() {
    FILE *arquivo = fopen("hardware.dat", "rb+");

    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int registro;
    puts("Digite o número do registro (0-99): ");
    scanf("%d", &registro);
    getchar(); 

    if (registro < 0 || registro >= MAX_FERRAMENTAS) {
        puts("Número de registro inválido.\n");
        fclose(arquivo);
        return;
    }

    struct Ferramenta ferramenta;

    puts("Digite o nome da ferramenta: ");
    fgets(ferramenta.nome, sizeof(ferramenta.nome), stdin);
    ferramenta.nome[strcspn(ferramenta.nome, "\n")] = 0;

    puts("Digite a quantidade: ");
    scanf("%d", &ferramenta.quantidade);

    puts("Digite o custo: ");
    scanf("%f", &ferramenta.custo);

    ferramenta.registro = registro;

    fseek(arquivo, registro * sizeof(struct Ferramenta), SEEK_SET);
    fwrite(&ferramenta, sizeof(struct Ferramenta), 1, arquivo);

    fclose(arquivo);
    puts("Ferramenta adicionada/atualizada com sucesso.\n");
}

void listarFerramentas() {
    FILE *arquivo = fopen("hardware.dat", "rb");

    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    struct Ferramenta ferramenta;
    puts("\n--- Lista de Ferramentas ---\n");

    for (int i = 0; i < MAX_FERRAMENTAS; i++) {
        fseek(arquivo, i * sizeof(struct Ferramenta), SEEK_SET);
        fread(&ferramenta, sizeof(struct Ferramenta), 1, arquivo);

        if (ferramenta.registro != 0) {
            printf("Registro %d: Nome: %s, Quantidade: %d, Custo: %.2f\n", ferramenta.registro, ferramenta.nome, ferramenta.quantidade, ferramenta.custo);
        }
    }

    fclose(arquivo);
}

void excluirFerramenta() {
    FILE *arquivo = fopen("hardware.dat", "rb+");

    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int registro;
    puts("Digite o número do registro para excluir (0-99): ");
    scanf("%d", &registro);

    if (registro < 0 || registro >= MAX_FERRAMENTAS) {
        puts("Número de registro inválido.\n");
        fclose(arquivo);
        return;
    }

    struct Ferramenta ferramentaVazia = {0, "", 0, 0.0};

    fseek(arquivo, registro * sizeof(struct Ferramenta), SEEK_SET);
    fwrite(&ferramentaVazia, sizeof(struct Ferramenta), 1, arquivo);

    fclose(arquivo);
    puts("Ferramenta excluída com sucesso.\n");
}

int main() {
    int opcao;

    inicializarArquivo();

    do {
        puts("\n--- Menu ---\n");
        puts("1. Inserir/Atualizar Ferramenta\n");
        puts("2. Listar Ferramentas\n");
        puts("3. Excluir Ferramenta\n");
        puts("4. Sair\n");
        puts("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirFerramenta();
                break;
            case 2:
                listarFerramentas();
                break;
            case 3:
                excluirFerramenta();
                break;
            case 4:
                puts("Saindo...\n");
                break;
            default:
                puts("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}