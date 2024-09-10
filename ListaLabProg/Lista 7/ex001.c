#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario {
    char nome[100];
    int idade;
    char email[100];
};

void preencherUsuario(struct Usuario *usuario) {
    puts("Digite o nome do usuario: ");
    fgets(usuario -> nome, sizeof(usuario -> nome), stdin);
    usuario -> nome[strcspn(usuario -> nome, "\n")] = 0; 

    puts("Digite a idade do usuario: ");
    scanf("%d", &(usuario -> idade));
    getchar(); 

    puts("Digite o email do usuario: ");
    fgets(usuario -> email, sizeof(usuario -> email), stdin);
    usuario -> email[strcspn(usuario -> email, "\n")] = 0;
}

void salvarCSV(struct Usuario *usuarios, int quantidade, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome, Idade, Email\n");

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s, %d, %s\n", usuarios[i].nome, usuarios[i].idade, usuarios[i].email);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso no arquivo %s.\n", nomeArquivo);
}

int main() {
    int quantidade;

    puts("Digite a quantidade de usuarios: ");
    scanf("%d", &quantidade);
    getchar(); 

    struct Usuario *usuarios = (struct Usuario*) malloc(quantidade * sizeof(struct Usuario));

    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Usuario %d ---\n", i + 1);
        preencherUsuario(&usuarios[i]);
    }

    salvarCSV(usuarios, quantidade, "usuarios.csv");

    free(usuarios);

    return 0;
}