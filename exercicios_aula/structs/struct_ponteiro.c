#include <stdio.h>
typedef struct{
    int dia, mes, ano;
}Data;
void entrada(Data *data){
    printf("\nDia: ");
    scanf("%d", &data->dia);
    printf("\nMes: ");
    scanf("%d", &data->mes);
    printf("\nAno: ");
    scanf("%d", &data->ano);
}
void imprimirData(Data *data){
    printf("%d/%d/%d", data->dia, data->mes, data->ano);
}
void categoria(Data *data){
    int idade = 2022 - data->ano;
    printf("\nIdade: %d", idade);
    if (idade < 10){
        printf("\nCrianca");
    }else if (idade > 10 && idade < 17){
        printf("\nAdolescente");
    }else if(idade > 17 && idade < 40){
        printf("\nAdulto");
    }else {
        printf("\nIdoso");
    }
}
int main(){
    Data data;
    Data *ponteiro;
    ponteiro = &data;
    entrada(ponteiro);
    imprimirData(ponteiro);
    categoria(ponteiro);

    return 0;
}