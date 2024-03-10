#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    
    int valor = abs(num);
    
    printf("O valor absoluto de %d é %d.\n", num, valor);
    
    return 0;
}
