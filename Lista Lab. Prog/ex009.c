#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;

    printf("Digite um valor inteiro: ");
    scanf("%d", &num);

    printf("O sucessor de %d é %d\n",num, num+1);

    printf("O antecessor de %d é %d\n", num, num-1);

    return 0;
}
