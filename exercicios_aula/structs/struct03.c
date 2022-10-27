#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[40];
    char disciplina[100];
    float nota_prova1, nota_prova2, nota_prova3;
}ficha_de_aluno;

void imprimir(ficha_de_aluno aluno){
    printf("\n\nFicha do aluno: ");
    printf("\nNome: %s", aluno.nome);
    printf("\nDisciplina: %s", aluno.disciplina);
    printf("\nNota 1: %.2f", aluno.nota_prova1);
    printf("\nNota 2: %.2f", aluno.nota_prova2);
    printf("\nNota 3: %.2f", aluno.nota_prova3);
}

ficha_de_aluno nova_ficha(){
    ficha_de_aluno aluno;
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(aluno.nome, 40, stdin);
    printf("\nDigite a disciplina: ");
    fflush(stdin);
    fgets(aluno.disciplina, 100, stdin);
    printf("\nNota 1: ");
    scanf("%f", &aluno.nota_prova1);
    printf("\nNota 2: ");
    scanf("%f", &aluno.nota_prova2);
    printf("\nNota 3: ");
    scanf("%f", &aluno.nota_prova3);
    return aluno;
}

void mediaNotas(float nota1, float nota2, float nota3){
    float media = (nota1+nota2+nota3)/3;
    printf("%.2f", media);
}
int i;
ficha_de_aluno aluno[3];
int main(){
    for (i = 0; i < 3; i++){
        aluno[i] = nova_ficha();
    }
    for (i = 0; i < 3; i++){
        imprimir(aluno[i]);
    }
    for ( i = 0; i < 3; i++){
        printf("\nMedia aluno %s", aluno[i].nome);
        mediaNotas(aluno[i].nota_prova1, aluno[i].nota_prova2, aluno[i].nota_prova3);
    }
    

    return 0;
}