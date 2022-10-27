/*
Declarar, alimentar e exibir os elementos de uma matriz
quadrada de ordem 3, ou seja, 3 linhas por 3 colunas.
*/
#include <stdio.h>
#define n 3
int main(){
    int count=0,i, j, m[n][n];
    for (i = 0; i < n; i++){
        printf("Informe os elementos da linha %d:\n", i);
        for (j = 0; j < n; j++){
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
            if (m[i][j] == 0){
                count++;
            }
        }
        printf("\n");
    }
    printf("\n");
    for ( i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf(" %d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\nNumero de zeros: %d", count);
    
    return 0;
}