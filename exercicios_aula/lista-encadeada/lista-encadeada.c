#include <stdio.h>
#include <stdlib.h>
struct lista{
    int matricula;
    struct lista* proximo;
};
typedef struct lista Lista;
/*Função de inicialização: retorna uma lista vazia.*/
Lista* inicializa(){
    return NULL;
}
Lista* cria(int valor)
{
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->matricula = valor;
    return p;
}
/*Inserção de um valor no início: retorna a lista atualizada*/
Lista* insere(Lista* lista, int valor){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->matricula = valor;
    novo->proximo = lista;

    return novo;
}
/*Inserção ordenada: retorna a lista atualizada*/
Lista* insere_ordenado(Lista* lista, int valor)
{
    Lista* novo = cria(valor); /* cria novo nó */
    Lista* anterior = NULL; /* ponteiro para elemento anterior */
    Lista* p = lista; /* ponteiro para percorrer a lista*/
    /* procura posição de inserção */
    while (p != NULL && p->matricula < valor) {
        anterior = p;
        p = p->proximo;
    }
    /* insere elemento */
    if (anterior == NULL) { /* insere elemento no início */
        novo->proximo = lista;
        lista = novo;
    }
    else { /* insere elemento no meio da lista */
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
    return lista;
}
/*Função vazia: retorna 1 se estiver vazia, 0 se estiver algum elemento*/
int vazia(Lista* lista){
    if (lista == NULL){
        return 1;
    }
    return 0;
}
/*Função retira: retirar elemento da lista*/
Lista* retira(Lista* lista, int valor){
    Lista* anterior = NULL;/*Ponteiro para elemento anterior*/
    Lista* p = lista;/*Ponteiro para percorrer a lista*/
    /*Procura elemento na lista, guardando o anterior*/
    while (p != NULL && p->matricula != valor){
        anterior = p;
        p = p->proximo;
    }
    /*Verifica se achou elemento*/
    if (p == NULL)
        return lista;
    /*Retira elemento*/
    if (anterior == NULL){
        lista = p->proximo;
    } else{
        anterior->proximo = p->proximo;
    }
    free(p);
    return lista;
}
/*Função para imprimir elementos da lista*/
void imprime(Lista* lista){
    Lista* p; /*Variavel para percorrer a lista*/
    for ( p = lista; p != NULL; p = p->proximo){
        printf("\nMatricula: %d \n", p->matricula);
    }
    printf("\n--------------");
}
void libera(Lista* lista){
    Lista* p = lista;
    while(p != NULL){
        /*Lista* temp = p->proximo; Guarda referencia para o proximo elemento*/
        free(p);
        /*p = temp*/
    }
}
int main(){
    Lista* lista; /*Declara uma lista naão inicializada*/
    lista = inicializa(); /*Inicializa lista vazia*/
    
    lista = insere_ordenado(lista, 8); /*Insere o elemento 8 na lista*/
    lista = insere_ordenado(lista, 10); /*Insere o elemento 10 na lista*/
    lista = insere_ordenado(lista, 2);
    lista = insere_ordenado(lista, 4);
    
    imprime(lista);   
    
    return 0;
}


