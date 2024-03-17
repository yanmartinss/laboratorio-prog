#include <stdio.h>

int main() {
    int t1 = 0, t2 = 1, t3;

    printf("Os primeiros vinte termos da sequência de Fibonacci são:\n");

    printf("%d ", t1);

    for (int i = 1; i < 20; i++) {
        printf("%d ", t2);
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    }

    return 0;
}
