#include <stdio.h>

int main(){

    float altura, imc;
    char sexo;

    printf("Digite sua altura em metros: ");
    scanf("%f", &altura);

    while (getchar() != '\n');

    printf("Digite seu sexo [M/F]: ");
    scanf("%c", &sexo);

    if (sexo == 'M'){
        imc = 72.7 * altura - 58;
    }else if (sexo == 'F'){
        imc = 62.1 * altura - 44.7;
    }

    printf("O seu peso ideal para sua altura é: %.1f\n", imc);

    return 0;
}
