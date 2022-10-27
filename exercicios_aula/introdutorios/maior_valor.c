/* Efeituar a leitura de tr�s n�meros inteiros e apresentar o maior valor*/
#include <stdio.h>
#include <locale.h>
void main(){
    setlocale(LC_ALL, "Portuguese");
    int numero1=0, numero2=0, numero3=0;
    printf("informe um valor inteiro: ");
    scanf("%d", &numero1);
    printf("informe outro valor inteiro: ");
    scanf("%d", &numero2);
    printf("informe outro valor inteiro: ");
    scanf("%d", &numero3);

    if (numero1 > numero2 && numero1 > numero3){
        printf("%d é o maior número", numero1);
    }else if (numero2 > numero1 && numero2 > numero3){
        printf("%d é o maior número", numero2);
    }else{
        printf("%d é o maior número", numero3);
    }
}
