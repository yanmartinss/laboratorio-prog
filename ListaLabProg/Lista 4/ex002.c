#include <stdio.h>

int main() {
    int num1, num2;
    int *ptr1, *ptr2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    ptr1 = &num1;
    ptr2 = &num2;

    printf("Antes da troca:\n");
    printf("num1 = %d, num2 = %d\n", *ptr1, *ptr2);

    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    printf("Depois da troca:\n");
    printf("num1 = %d, num2 = %d\n", *ptr1, *ptr2);

    return 0;
}