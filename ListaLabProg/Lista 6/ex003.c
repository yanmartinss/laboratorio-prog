#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vetor {
    int *elementos;   
    int quantidade;   
    float media;       
};

void gerarVetor(struct Vetor *v, int quantidade) {
    v -> quantidade = quantidade;
    v -> elementos = (int*) malloc(quantidade * sizeof(int)); 

    srand(time(NULL)); 

    puts("Elementos do vetor:\n");
    for (int i = 0; i < quantidade; i++) {
        v -> elementos[i] = rand() % 100; 
        printf("%d ", v -> elementos[i]); 
    }
    puts("\n");
}

void calcularMedia(struct Vetor *v) {
    int soma = 0;
    for (int i = 0; i < v -> quantidade; i++) {
        soma += v -> elementos[i];
    }
    v -> media = (float)soma / v -> quantidade;
}

int main() {
    struct Vetor v; 
    int quantidade;

    puts("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &quantidade);

    gerarVetor(&v, quantidade);
    calcularMedia(&v);

    printf("A media dos elementos do vetor e: %.2f\n", v.media);

    free(v.elementos);

    return 0;
}