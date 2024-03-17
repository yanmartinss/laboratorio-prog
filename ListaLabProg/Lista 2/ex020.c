#include <stdio.h>

int main(){

    int fat = 1;

    for (int i = 1; i <= 10; i++){
        fat *= i;
        if (i % 2 == 1){
            printf("Fatorial de %d: %d\n", i, fat);
        }
    }

    return 0;
}
