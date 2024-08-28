#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;
    int *ptr_num1 = &num1, *ptr_num2 = &num2;

    puts("Digite o primeiro número: ");
    scanf("%d", ptr_num1);
    puts("Digite o segundo número: ");
    scanf("%d", ptr_num2);

    printf("Antes da troca: num1 = %d, num2 = %d\n", *ptr_num1, *ptr_num2);

    trocar(ptr_num1, ptr_num2);

    printf("Depois da troca: num1 = %d, num2 = %d\n", *ptr_num1, *ptr_num2);

    return 0;
}