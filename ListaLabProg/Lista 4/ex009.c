#include <stdio.h>

int main() {
    int n;

    puts("Digite o numero de elementos: ");
    scanf("%d", &n);

    int arr[n];

    puts("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }

    puts("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    puts("\n");

    return 0;
}