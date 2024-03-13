#include <stdio.h>

int main() {
    int jose = 150, pedro = 110, crescimento = 1, anos;
    
    for (anos = 0; pedro <= jose; anos++) {
        pedro += crescimento;
    }

    printf("Pedro será maior que José em %d anos.\n", anos);

    return 0;
}
