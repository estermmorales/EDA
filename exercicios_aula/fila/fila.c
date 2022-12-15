#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no {
    float elemento;
    struct no* proximo;
};
typedef struct no No;

struct fila {
    No* inicio;
    No* fim;
};

Fila* cria() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = fila->fim = NULL;
    return fila;
}
/*Função auxiliar: insere no fim*/
No* insere_fim(No* fim, float valor) {
    No* p = (No*) malloc(sizeof(No));
    p->elemento = valor;
    p->proximo = NULL;

    if(fim != NULL){
        fim->proximo = p;
    }
    return p;
}
/*Função auxiliar: retira do inicio*/
No* retira_inicio(No* inicio) {
    No* p = inicio->proximo;
    free(inicio);
    return p;
}

void insere(Fila* fila, float valor) {
    fila->fim = insere_fim(fila->fim, valor);
    if (fila->inicio == NULL) {
        fila->inicio = fila->fim;
    }
}

int vazia(Fila* fila) {
    return (fila->inicio == NULL);
}

float retira(Fila* fila) {
    if (vazia(fila)) {
        printf("Fila esta vazia!\n");
        exit(1);
    }
    float valor;
    valor = fila->inicio->elemento;

    fila->inicio = retira_inicio(fila->inicio);
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    return valor;
}

void libera(Fila* fila) {
    No* liberando = fila->inicio;

    while (liberando != NULL) {
        No* auxProximo = liberando->proximo;
        free(liberando);
        liberando = auxProximo;
    }
    free(fila);
}

void imprime(Fila* fila) {
    No* itens;
    for (itens = fila->inicio; itens != NULL; itens = itens->proximo) {
        printf("%.1f\t", itens->elemento);
    }
}

int main() {
    Fila* fila = cria();
    insere(fila, 5.3);
    insere(fila, 0.0);
    insere(fila, 2.5);
    insere(fila, 5.2);
    insere(fila, 3.1);

    imprime(fila);
    printf("\nRetira primeiro elemento (%.1f)\n", retira(fila));
    imprime(fila);




}





