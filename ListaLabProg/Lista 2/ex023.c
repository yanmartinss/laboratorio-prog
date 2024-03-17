#include <stdio.h>

int main() {
    int x = 5, pre, pos;

    printf("Antes do pré-incremento, x = %d\n", x);
    pre = --x;
    printf("Depois do pré-incremento, x = %d\n", x);
    x = 5;
    printf("Antes do pós-incremento, x = %d\n", x);
    pos = x--;
    printf("Depois do pós-incremento, x = %d\n", x);

    return 0;
}
