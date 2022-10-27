#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
} DataNascimento;

typedef struct {
    DataNascimento data;
    char nome[40];
    int idade;
    char sexo;
} Pessoa;

void imprimir(Pessoa p){
    printf("\nNome: %s", p.nome);
    printf("\nIdade: %d", p.idade);
    printf("\nSexo: %c", p.sexo);
    printf("\nData de nascimento: %d/%d/%d", p.data.dia, p.data.mes, p.data.ano);
}

Pessoa lerPessoa(){
    Pessoa pessoa;
    printf("Digite o nome: ");
    fgets(pessoa.nome, 40, stdin);
    printf("\nDigite o sexo (F ou M): ");
    scanf("%c", &pessoa.sexo);
    printf("\nDigite a idade: ");
    scanf("%d", &pessoa.idade);

    printf("Digite sua data de nascimento (dd/mm/aaaa); \n");
    scanf("%d %d %d", &pessoa.data.dia, &pessoa.data.mes, &pessoa.data.ano);
    return pessoa;
};


int main(){
    int i;
    Pessoa pessoa[3];
    for (i = 0; i < 3; i++){
        pessoa[i] = lerPessoa();
    }
    for (i = 0; i < 3; i++){
        imprimir(pessoa[i]);
    }
    
    return 0;
}
