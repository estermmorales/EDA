/*
Criar um vetor A com 8 elementos inteiros.
Construir um vetor B de mesmo tipo e tamanho e com os elementos do
vetor A multiplicados por 2, ou seja:
B[i] = A[i] * 2 
 */
#include <stdio.h>

void main(){
    int const n = 8; 
    int i, a[n], b[n];
    
    for (i = 0; i < n; i++){
        printf("Informe o %do. elemento: ", i+1);
        scanf("%d", &a[i]);
    }
    
    for (i = 0; i < n; i++){
       b[i] = a[i] * 2;
    }

    printf("\n----------------------\n");
    for (i = 0; i < n; i++){
        printf("%d - %d \n", a[i], b[i]);
    }

}