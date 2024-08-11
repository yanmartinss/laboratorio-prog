// USANDO (*ptr): CONTEÚDO DO ENDEREÇO DA VARIÁVEL QUE ptr APONTA
// USANDO (ptr): O ENDEREÇO DA VARIÁVEL
// USANDO (&ptr): ENDEREÇO DO PONTEIRO

#include <stdio.h>
#include <stdlib.h>

int main() {
    int var = 15;
    int *ptr_var = &var;

    printf("Conteudo de var: %d\n", var);
    printf("Endereco de var: %p\n", &var);

    printf("Conteudo apontado por ptr_var: %d\n", *ptr_var);
    printf("Endereco apontador por ptr_var: %p\n", ptr_var);
    printf("Endereco do ptr_var: %p", &ptr_var);

    *ptr_var = 73; 

    puts("\n\n");
    printf("Conteudo de var: %d\n", var);
    printf("Endereco de var: %p\n", &var);
    printf("Conteudo apontado por ptr_var: %d\n", *ptr_var);
    printf("Endereco apontador por ptr_var: %p\n", ptr_var);
    printf("Endereco do ptr_var: %p\n", &ptr_var);

    puts("\nEnd");
    return 0;
}