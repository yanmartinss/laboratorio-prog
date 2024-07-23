#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
    char x[SIZE];
    char c;
    int count = 0;

    puts("Digite uma string: ");
    fgets(x, sizeof(x), stdin);

    x[strcspn(x, "\n")] = '\0';

    puts("Digite um caractere: ");
    scanf("%c", &c);

    for (int i = 0; x[i] != '\0'; i++) {
        if (x[i] == c) {
            count++;
        }
    }

    printf("O caractere '%c' aparece %d vezes na string.\n", c, count);

    return 0;
}