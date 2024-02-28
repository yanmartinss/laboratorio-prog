#include <stdio.h>

int main(){

    float volume, comprimento, largura, altura;

    printf("Descobrir o volume de uma caixa retangular\n");

    printf("Digite o comprimento da caixa: ");
    scanf("%f", &comprimento);

    printf("Digite a largura da caixa: ");
    scanf("%f", &largura);

    printf("Digite a altura da caixa: ");
    scanf("%f", &altura);

    volume = comprimento * largura * altura;

    printf("O volume dessa caixa retangular é: %.2fL\n", volume);

    return 0;
}
