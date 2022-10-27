#include <stdio.h>

void somaprod(int a, int b, int *c, int *d){
    *c = a + b;
    *d = a * b;
}

int main(){
    int s, p;
    somaprod(3, 5, &s, &p);
    printf("Soma = %d e Produto = %d\n", s, p);


    return 0;
}