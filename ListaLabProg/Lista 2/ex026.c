#include <stdio.h>

int main(){

    for (int i = 1; i <= 256; i++){
        printf("Decimal: %d\t", i);
        //printf("Binário: %08b\t", i);
        printf("Octal: %o\t", i);
        printf("Hexadecimal: %X\n", i);
    }

    return 0;
}
