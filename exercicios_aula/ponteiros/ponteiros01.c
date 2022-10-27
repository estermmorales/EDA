#include <stdio.h>

void main(){
    // Declarando um ponteiro, é necessário especificar seu tipo e utilizar o caractere ‘*’.
    int *ponteiro;
    int variavel = 10;
    // Apontando para o endereço de memória da variavel utilizando o operador de endereço '&'.
    ponteiro = &variavel; 
    
    // Acessando o endereço de memória da variavel 
    printf("Endereço da variável: %p\n", &variavel);
    // Acessando o conteúdo do ponteiro, que é o endereço de memória da variável
    printf("Contéudo da variável ponteiro: %p\n", ponteiro);
    // Acessando o endereço de memória do ponteiro, que é diferente do endereço da variável
    printf("Endereço da variável ponteiro: %p\n", &ponteiro);
    // Acessando o conteúdo da variável apontada pelo ponteiro, que é o número 10.
    printf("Conteúdo da variável apontada pelo ponteiro: %d\n", *ponteiro);
}