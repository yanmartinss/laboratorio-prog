#include <stdio.h>

void somar(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}

int main() {
    int num1, num2, soma;
    int *ptr_num1 = &num1, *ptr_num2 = &num2, *ptr_soma = &soma; 

    puts("Digite o primeiro número: ");
    scanf("%d", ptr_num1);
    puts("Digite o segundo número: ");
    scanf("%d", ptr_num2);

    somar(ptr_num1, ptr_num2, ptr_soma);

    printf("A soma é: %d\n", *ptr_soma);
    printf("O endereço de memória onde o resultado está armazenado é: [%p]\n", (void*)ptr_soma);

    return 0;
}