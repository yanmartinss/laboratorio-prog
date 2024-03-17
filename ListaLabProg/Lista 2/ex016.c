#include <stdio.h>

int main(){

    int soma1 = 0, soma2 = 0;

    for (int i = 0; i <= 100; i += 3){
        soma1 += i;
    }

    for (int i = 100; i <= 200; i +=5){
        if (i % 5 == 0){
            soma2 += i;
        }
    }

    printf("Soma dos números divisíveis por 3 no intervalo [0, 100]: %d\n", soma1);
    printf("Soma dos números divisíveis por 5 no intervalo [100, 200]: %d\n", soma2);

    return 0;
}
