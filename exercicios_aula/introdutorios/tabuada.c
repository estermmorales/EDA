#include <stdio.h>
#include <stdlib.h>

void main(){
    int valor, i;
    printf("Insira o valor: \n");
    scanf("%d", &valor);
    for(i = 1; i <= 10; i++){
        printf("\n%d X %d = %d",valor, i, valor * i);
    }
}