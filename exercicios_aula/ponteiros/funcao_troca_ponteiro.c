#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a = 1, b = 2;
    troca(&a, &b);
    printf("a: %d e b: %d", a, b);

    return 0;
}