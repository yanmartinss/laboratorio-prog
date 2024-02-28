#include <stdio.h>

int main(){

    int n1,n2,n3;


    n1 = 7 + 3*6/2-1;
    printf("n1 = 7 + 3*6/2-1\n\n");
    printf("Primeiro vem a multiplicação depois a divisão e depois a soma, resultado: %d\n",n1);


    n2 = 2%2 + 2*2-2/2;
    printf("n2 = 2%%2 + 2*2-2/2\n\n");
    printf("Primeiro vem a divisão, multiplicação e a %% e depois a soma e a subtração, resultado: %d\n",n2);

    n3 = (3*9*(3 + (9*3/(3))));
    printf("n3 = (3 * 9 * (3 + (9*3/ (3) ) ) )\n\n");
    printf("Primeiro vem o 9*3, depois divide pelo 3, que soma o 3 de fora do parênteses e multiplica com o 9 e o 3 de fora dos últimos parenteses\n ");

    return 0;
}
