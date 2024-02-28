#include <stdio.h>

int main() {

    int num;

    printf("Digite um valor inteiro: ");
    scanf("%d", &num);

    printf("Seu triplo: %d\n", num*3);
    printf("Seu quadrado: %d\n", num*num);
    printf("Seu meio: %d\n", num/2);

    return 0;
}
