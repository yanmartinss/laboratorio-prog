#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;

    printf("Digite um número: : ");
    scanf("%d", &num);

    printf("%d em hexadecimal: %x\n", num, num);

    printf("%d em octal: %o\n", num, num);

    return 0;
}
