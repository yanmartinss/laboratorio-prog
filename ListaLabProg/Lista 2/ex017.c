#include <stdio.h>

int main(){

    int f;

    for(int i = 10; i <= 100; i+=10){
        f = 1.8 * i + 32;
        printf("Celsius: %d; Fahrenheit: %d\n", i, f);
    }

    return 0;
}
