#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){

    char str1[SIZE], str2[SIZE];

    /* USANDO STRCAT: */
    puts("Digite uma frase: ");
    fgets(str1, SIZE, stdin);

    puts("Digite a continuação: ");
    fgets(str2, SIZE, stdin);

    printf(strcat(str1, str2));

    /* SEM USAR STRCAT: */
    int len_str1 = strlen(str1);

    for (int i = 0; str2[i] != '\0'; i++) {
        str1[len_str1 + i] = str2[i];
    }
    str1[len_str1 + strlen(str2)] = '\0';

    printf("String concatenada: %s\n", str1);

    return 0;
}