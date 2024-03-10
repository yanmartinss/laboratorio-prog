#include <stdio.h>

int main() {
    float hora_aula, horastrab, inss;
    
    printf("Digite o valor da hora aula: ");
    scanf("%f", &hora_aula);
    
    printf("Digite o número de horas trabalhadas no mês: ");
    scanf("%f", &horastrab);
    
    printf("Digite o percentual de desconto do INSS: ");
    scanf("%f", &inss);
    
    float salario_bruto = hora_aula * horastrab;
    
    float desconto_inss = salario_bruto * (inss / 100);
    
    float salario_liquido = salario_bruto - desconto_inss;
    
    printf("Salário bruto: R$ %.2f\n", salario_bruto);
    printf("Salário líquido: R$ %.2f\n", salario_liquido);
    
    return 0;
}
