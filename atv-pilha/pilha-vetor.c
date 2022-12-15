#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
Pilha* cria (void);
void empilha (Pilha* p, float v);
float desempilha (Pilha* p);
int vazia (Pilha* p);
void libera (Pilha* p);
void imprime(Pilha* p);
/*Define tamanho do vetor*/
#define MAX 50
struct pilha {
    int n;
    float vet[MAX];
};
/*Função para criar a pilha*/
Pilha* cria (void)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; /* inicializa com zero elementos */
    return p;
}
/*Função para inserir elemento no topo da pilha*/
void empilha (Pilha* p, float v)
{
    if (p->n == MAX) { /* capacidade esgotada */
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
 /* insere elemento na próxima posição livre */
    p->vet[p->n] = v;
    p->n++;
}
/*Função para remover elemento do topo da*/
float desempilha (Pilha* p) {
    float v;
    if (vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
 /* retira elemento do topo */
    v = p->vet[p->n-1];
    p->n--;
    return v;
}
/*Função para verificar se pilha está vazia*/
int vazia (Pilha* p)
{
    return (p->n == 0);
}
/*Função para liberar pilha*/
void libera (Pilha* p)
{
    free(p);
}
/*Função para imprimir pilha*/
void imprime (Pilha* p)
{
    int i;
    for (i=p->n-1; i>=0; i--)
        printf("%.1f\t",p->vet[i]);
    printf("\n-----------\n");
}

int main() {
    Pilha* pilha = cria();
    int opcao;
    float valor;
    do{
        printf("\n 0 - Sair\n 1 - Inserir na pilha\n 2 - Retirar da pilha \n 3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um valor: ");
            scanf("%f", &valor);
            empilha(pilha, valor);
            printf("\n Valor inserido");
            break;
        case 2:
            valor = desempilha(pilha);
            printf("\n Valor retirado: %.1f", valor);
            break;
        case 3:
            imprime(pilha);
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
    }while(opcao != 0);
}