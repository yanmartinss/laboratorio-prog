#include <stdio.h>

int main() {
    char str[100];
    char *ptr;
    int length = 0;

    puts("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    for (ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == '\n') {
            *ptr = '\0';
            break;
        }
    }

    for (ptr = str; *ptr != '\0'; ptr++) {
        length++;
    }

    printf("O comprimento da string é: %d\n", length);

    return 0;
}