s
#include <string.h>

#define size 100
#define finalSize 200

int main() {
    char str1[size], str2[size], strResultado[finalSize];
    char *ptrStr1 = str1;
    char *ptrStr2 = str2;
    char *ptrResultado = strResultado;

    puts("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    puts("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    while (*ptrStr1 != '\0') {
        *ptrResultado = *ptrStr1;
        ptrResultado++;
        ptrStr1++;
    }

    while (*ptrStr2 != '\0') {
        *ptrResultado = *ptrStr2;
        ptrResultado++;
        ptrStr2++;
    }

    *ptrResultado = '\0';

    printf("String resultante: %s\n", strResultado);

    return 0;
}