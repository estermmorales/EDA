/*Empilhar valores inteiros*/
#include <stdio.h>
#include <stdlib.h>
struct No
{
    int numero;
    struct No *atual;
};
typedef struct No no;
int tamanho;


int menu();
void inicia(no *pilha);
void opcao(no *pilha, int opcao);
void exibe(no *pilha);
void libera(no *pilha);
void empilhar(no *pilha);
no *desempilhar(no *pilha);

int menu(){
    int opcao;
    printf("Escolha a opção desejada: \n");
    printf("0. Sair \n");
    printf("1. Zerar pilha \n");
    printf("2. Exibir pilha: \n");
    printf("3. Empilhar  \n");
    printf("4. Desempilhar \n");
    scanf("%d", &opcao);
    return opcao;
}
void opcao(no *pilha, int opcao){
    no *temp;
    switch (opcao){
    case 0:
        libera(pilha);
        break;
    case 1:
        libera(pilha);
        inicia(pilha);
        break;
    case 2:
        exibe(pilha);
        break;
    case 3:
        empilhar(pilha);
        break;
    case 4:
        temp = desempilhar(pilha);
        if (temp != NULL){
            printf("\nRetirado da pilha o elemento %d\n", temp->numero);
        }
        break;
    default:
        printf("Comando invalido.\n\n");
        break;
    }
}
void inicia(no *pilha){
    pilha->atual = NULL;
    tamanho = 0;
}
int vazia(no *pilha){
    if (pilha->atual == NULL){
        return 1;
    }
    return 0;
}

no *aloca(){
    no *novo = (no*) malloc(sizeof(no));
    if(!novo){
        printf("\nSem memoria.\n");
        exit(1);
    }
    printf("Informe elemento: ");
    scanf("%d", &novo->numero);
    return novo;
}

void libera(no *pilha){
    if (!vazia(pilha)){
        no *proximoNo, *noAtual;
        noAtual = pilha->atual;
        while (noAtual != NULL){
            proximoNo = noAtual->atual;
            free(noAtual);
            noAtual = proximoNo;
        }
    }
}

void exibe(no *pilha){
    if (vazia(pilha)){
        printf("Pilha vazia\n\n");
        return;
    }
    no *auxiliar;
    auxiliar = pilha->atual;
    printf("Pilha tem os seguintes elementos:\n");
    while (auxiliar != NULL){
        printf("%5d", auxiliar->numero);
        auxiliar = auxiliar->atual;
    }
    printf("\n");
}
// push
void empilhar(no *pilha){
    no *novo = aloca();
    novo->atual = NULL;
    if (vazia(pilha)){
        pilha->atual = novo;
    } else{
        no *auxiliar = pilha->atual;
        while(auxiliar->atual != NULL){
            auxiliar = auxiliar->atual;
        }
        auxiliar->atual = novo;
    }
    
}
// pop
no *desempilhar(no *pilha){
    if(pilha->atual == NULL){
        printf("\nPilha vazia\n");
        return NULL;
    } else{
        no *ultimo = pilha->atual, *penultimo = pilha;
        while(ultimo->atual != NULL){
            penultimo = ultimo;
            ultimo = ultimo->atual;
        }
        penultimo->atual == NULL;
        return ultimo;
    }
}
int main(){
    no *pilha = (no*) malloc(sizeof(no));
    if(!pilha){
        printf("\nSem memoria.\n");
        exit(1);
    }
    inicia(pilha);
    int aux;
    do{
        aux = menu();
        opcao(pilha, aux);
    }while(aux);
    free(pilha);
    return 0;
}