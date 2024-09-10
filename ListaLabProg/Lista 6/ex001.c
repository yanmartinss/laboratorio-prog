#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    float nota1;
    float nota2;
    float media;
};

void calcularMedia(struct Aluno *aluno) {
    aluno -> media = (aluno -> nota1 + aluno -> nota2) / 2;
}

int main() {
    struct Aluno *aluno = (struct Aluno*) malloc(sizeof(struct Aluno));

    puts("Digite a primeira nota: ");
    scanf("%f", &(aluno -> nota1));

    puts("Digite a segunda nota: ");
    scanf("%f", &(aluno -> nota2));

    calcularMedia(aluno);

    printf("A média do aluno é: %.1f\n", aluno -> media);

    free(aluno);

    return 0;
}