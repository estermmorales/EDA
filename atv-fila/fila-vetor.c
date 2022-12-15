#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
Fila* cria (void);
void insere (Fila* f, float v);
float retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);
void imprime (Fila* f);

/*Define tamanho da fila*/
#define N 100
struct fila {
    int inicio, fim;
    float vet[N];
};
/*Função para criar fila*/
Fila* cria (void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->fim = 0; /* inicializa fila vazia */
    return f;
}
/*Função auxiliar para incrementar o valor de um índice*/
int incrementa (int i)
{
    if (i == N-1)
        return 0;
    else
        return i+1;
}
/*Função para inserir elemento na fila*/
void insere (Fila* f, float v)
{
    if (incrementa(f->fim) == f->inicio) { /*Fila cheia*/
    printf("Capacidade da fila estourou.\n");
    exit(1); 
    }
    /*Insere elemento na próxima posição livre*/
    f->vet[f->fim] = v;
    f->fim = incrementa(f->fim);
}
/*Função para retirar primeiro elemento da fila*/
float retira (Fila* f)
{
    float v;
    if (vazia(f)) {
    printf("Fila vazia.\n");
    exit(1); 
    }
    /*Retira elemento do início*/
    v = f->vet[f->inicio];
    f->inicio = incrementa(f->inicio);
    return v;
}
/*Função para verificar se fila está vazia*/
int vazia (Fila* f)
{
    return (f->inicio == f->fim);
}
/*Função para esvaziar fila*/
void libera (Fila* f)
{
    free(f);
}
/*Função para imprimir fila*/
void imprime (Fila* f)
{
    int i;
    for (i=f->inicio; i!=f->fim; i=incrementa(i))
        printf(" %.1f\t",f->vet[i]);
    printf("\n-----------\n");
}

int main(){
    Fila* fila = cria();
    int opcao;
    float valor;
    do{
        printf("\n 0 - Sair\n 1 - Inserir na fila\n 2 - Retirar da fila \n 3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um valor: ");
            scanf("%f", &valor);
            insere(fila, valor);
            printf("\n Valor inserido");
            break;
        case 2:
            valor = retira(fila);
            printf("\n Valor retirado: %.1f", valor);
            break;
        case 3:
            imprime(fila);
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
    }while(opcao != 0);
}