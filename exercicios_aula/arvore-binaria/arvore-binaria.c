#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *direita, *esquerda;
} NoArvore;


NoArvore* inserir (NoArvore* raiz, int num) 
{
    /*Verifica se raiz é nula*/
    if (raiz == NULL) {
        NoArvore *aux = malloc(sizeof(NoArvore));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita= NULL;
        return aux;
    } else { /*Verifica se numero é menor que raiz*/
        if (num < raiz->valor)
            raiz->esquerda = inserir(raiz->esquerda, num);
        else 
            raiz->direita = inserir(raiz->direita, num);
        
        return raiz;
    }
}

void imprimir_1(NoArvore* raiz) {
    if (raiz) {
        printf("%d\t", raiz->valor);
        imprimir_1(raiz->esquerda);
        imprimir_1(raiz->direita);
    }
}

void imprimir_2(NoArvore* raiz) {
    if (raiz) {
        imprimir_1(raiz->esquerda);
        printf("%d\t", raiz->valor);
        imprimir_1(raiz->direita);
    }
}

int main(){
    NoArvore* raiz = NULL;
    int opcao, valor;
    do{
        printf("\n 0 - Sair\n 1 - Inserir\n 2 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um valor: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            printf("\n Valor inserido.");
            break;
        case 2:
            printf("\n\n Imprimindo\n");
            imprimir_2(raiz);
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
    }while(opcao != 0);
}