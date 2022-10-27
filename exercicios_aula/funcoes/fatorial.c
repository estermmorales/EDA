/*Desenvolver uma estrutura modular com uma função que
calcula o fatorial de um número*/
#include <stdio.h>
int fatorial(int numero){
    int fat=1;
    while (numero != 0){
        fat *= numero;
        numero--;
    }
    return fat;
}
int main(){
    int numero;
    printf("Informe um numero: ");
    scanf("%d", &numero);
    printf("O numero informado é: %d\n", numero);
    printf("Fatorial: %d", fatorial(numero));
    return 0;
}