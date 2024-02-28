#include <stdio.h>

int main(){

    float valor, total;

    printf("Digite o valor da conta: ");
    scanf("%f", &valor);

    total = valor + ((10*valor)/100); 
    printf("Valor total da conta com os 10%% do garçom: R$%.2f\n", total);

    return 0;
}
