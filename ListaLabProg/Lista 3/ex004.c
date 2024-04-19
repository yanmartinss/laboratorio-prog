#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(){

    char str1[SIZE], str2[SIZE];
    int contem;

    puts("Digite a primeira frase: ");
    fgets(str1, SIZE, stdin);

    puts("Digite a segunda frase: ");
    fgets(str2, SIZE, stdin);

    /* SEM USAR O STRCMP: */

    for (int i = 0; i < strlen(str2); i++){
        if (str2[i] != str1[i]){
            contem = 0;
            break;
        } else {
            contem = 1;
        }
    }

    if (contem == 1){  
        puts("As strings são iguais");
    }else{
        puts("As strings não são iguais");
    }

    /* USANDO O STRCMP: */

    if (strcmp(str1, str2) == 0){  
        puts("As strings são iguais");
    } else {
        puts("As strings não são iguais");
    }

    return 0;
}
