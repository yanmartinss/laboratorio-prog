#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    float nota1;
    float nota2;
    float media;
};

void calcularMedia(struct Aluno *aluno) {
    aluno -> media = (aluno->nota1 + aluno->nota2) / 2;
}

void preencherAlunos(struct Aluno *alunos, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        puts("Digite a primeira nota: ");
        scanf("%f", &(alunos[i].nota1));

        puts("Digite a segunda nota: ");
        scanf("%f", &(alunos[i].nota2));

        calcularMedia(&alunos[i]);
    }
}

void exibirMedias(struct Aluno *alunos, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\nA média do aluno %d é: %.1f\n", i + 1, alunos[i].media);
    }
}

int main() {
    int quantidade = 3;
    struct Aluno *alunos = (struct Aluno*) malloc(quantidade * sizeof(struct Aluno)); 

    preencherAlunos(alunos, quantidade);

    exibirMedias(alunos, quantidade);

    free(alunos);

    return 0;
}