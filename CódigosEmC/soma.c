#include <stdlib.h>
#include <stdio.h>

int main(){
    int x, y, res;
    printf("Digite um valor para x: ");
    scanf("%d", &x);
    printf("Digite um valor para y: ");
    scanf("%d", &y);

    res = x + y;

    printf("O resultado de %d + %d eh igual a %d\n", x, y, res);

    return 0;
}
