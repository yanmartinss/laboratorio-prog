#include <stdio.h>
#include <math.h>

int main() {
    for(int i = 0; i <= 7; i++) {
        printf("3^%d = %d\n", i, (int)(pow(3, i)));
    }

    return 0;
}
