/*Desenvolver uma estrutura modular com uma função que calcula e
retorna a conversão de graus Fahrenheit (F) para Centigrados(C)
através da formula C=5/9(F-32).*/
#include <stdio.h>
float converta(float fahrenheit){
    return (5.0 / 9.0 * (fahrenheit - 32.0));
}
void main(){
    float fahrenheit;
    printf("Informe os graus em Fahrenheit: ");
    scanf("%f", &fahrenheit);
    printf("\n %.2f graus Fahrenheit = %.2f graus Centigrados", fahrenheit, converta(fahrenheit));

}