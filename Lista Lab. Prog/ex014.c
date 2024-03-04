#include <stdio.h>

int main(){

    int x, f;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%d", &x);

    f = (9*x + 160) / 5;

    printf("%d em Fahrenheit é %d\n", x, f);

    return 0;
}
