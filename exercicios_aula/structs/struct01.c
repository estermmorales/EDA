#include <stdio.h>

typedef struct {
    float x;
    float y;
} Ponto;

int main(){
    Ponto p;
    printf("\nDigite as coordenadas do ponto(x, y): ");
    scanf("%f %f", &p.x, &p.y);

    printf("O ponto fornecido foi: (%.2f, %.2f)\n", p.x, p.y);
    return 0;
}