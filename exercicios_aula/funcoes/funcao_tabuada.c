/*Desenvolver uma estrutura com um procedimento que recebe
através de parametro um número inteiro e apresenta a tabuada deste numero*/
#include <stdio.h>
void tabuada(int a){
    int i;
    for (i = 1; i <= 10; i++){
        printf("\n%d x %d = %d \n", i, a, i*a);
    }
}
void main(){
    int numero;
    printf("\nInforme um numero para a tabuada: \n");
    scanf("%d", &numero);

    printf("\nO número informado foi: %d ", numero);
    tabuada(numero);


}