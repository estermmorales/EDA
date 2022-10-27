#include <stdio.h>

void main(){
    float peso, altura, imc;
    printf("Informe o peso (em Kg): \n");
    scanf("%f", &peso);
    printf("Informe a altura (em metros): \n");
    scanf("%f", &altura);
    imc = peso / (altura*altura);
    printf("\n IMC: %.2f", imc);
    if (imc < 20)
        printf("\nAbaixo do peso");
    else if ((imc >= 20) && (imc < 25))
        printf("\nPeso normal");
    else if ((imc >= 25) && (imc < 30))
        printf("\nAcima do peso");
    else if ((imc >= 30) && (imc < 34))
        printf("\nObeso");
    else
        printf("\nMuito obeso");


}
