#include <stdio.h>

int main(){

    int num;

    printf("Qual número você quer mostrar a tabuada? ");
    scanf("%d", &num);

    for (int i = 1; i <=10; i++){
        printf("%d * %d = %d\n", num, i, i * num);
    }

    return 0;
}
