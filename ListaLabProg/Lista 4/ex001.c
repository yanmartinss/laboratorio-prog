#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, sum;
    int *ptr1, *ptr2, *ptr_sum;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    ptr1 = &num1;
    ptr2 = &num2;
    ptr_sum = &sum;

    *ptr_sum = *ptr1 + *ptr2;

    printf("A soma de %d e %d é %d\n", *ptr1, *ptr2, *ptr_sum);
    printf("O valor da soma está armazenado no endereço de memória: %p\n", (void*)ptr_sum);

    return 0;
}