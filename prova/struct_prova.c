#include <stdio.h>
typedef struct{
    char rua[100];
    char complemento[100];
    int cep;
}tipoEndereco;
typedef struct{
    tipoEndereco endereco;
    char nome[100];
    int cpf;
    int senha;
    float saldo;
}contaBancaria;
int i;
contaBancaria contas[3];
void criaContas(){
    for (i = 0; i < 3; i++){
        printf("\n-----------CADASTRO-----------");
        printf("\nDigite o nome: ");
        fflush(stdin);
        fgets(contas[i].nome, 100, stdin);
        printf("\nDigite o CPF: ");
        scanf("%d", &contas[i].cpf);
        printf("\nDigite a senha: ");
        scanf("%d", &contas[i].senha);
        contas[i].saldo = 0;
        printf("\nDigite endereco da rua: ");
        fflush(stdin);
        fgets(contas[i].endereco.rua, 100, stdin);
        printf("\nDigite o complemento: ");
        fflush(stdin);
        fgets(contas[i].endereco.complemento, 100, stdin);
        printf("\nDigite o CEP: ");
        scanf("%d", &contas[i].endereco.cep);
    }
}
void deposita(int cpf, float valor){
    for (i = 0; i < 3; i++){
        if (contas[i].cpf == cpf){
            printf("\n\nRealizando deposito...");
            contas[i].saldo = contas[i].saldo + valor;
            printf("\nDeposito realizado.");
        }
    }
}
void imprimeSaldo(int cpf, int senha){
    for (i = 0; i< 3; i++){
        if (contas[i].senha == senha && contas[i].cpf == cpf){
            printf("\n\Saldo da conta de %s %.2f", contas[i].nome, contas[i].saldo);
        }
    }
}
void saque(int cpf, int senha, float valor){
    for (i = 0; i < 3; i++){
        if (contas[i].senha == senha && contas[i].cpf == cpf){
            if (contas[i].saldo >= valor){
                printf("\nRealizando saque...");
                contas[i].saldo = contas[i].saldo - valor;
                printf("\nSaque realizado.");
            }else{
                printf("\nSaldo insufiente!");
            }
        }
    }
}
int main(){
    float valor;
    int operacao, cpfConta, senhaConta;
    while (operacao != 0){
        printf("\nEscolha a operacao: \n0 - Sair\n1 - Cadastrar contas\n2 - Ver saldo\n3 - Depositar\n4- Sacar\n");
        scanf("%d", &operacao);
        if (operacao == 1){
            criaContas();
        } else if (operacao == 2){
            printf("\nInforme o CPF: ");
            scanf("%d", &cpfConta);
            printf("\nInforme a senha: ");
            scanf("%d", &senhaConta);
            imprimeSaldo(cpfConta, senhaConta);
        } else if (operacao == 3){
            printf("\nInforme o CPF: ");
            scanf("%d", &cpfConta);
            printf("\nInforme valor do deposito: ");
            scanf("%f", &valor);
            deposita(cpfConta, valor);
        } else if (operacao == 4){
            printf("\nInforme o CPF: ");
            scanf("%d", &cpfConta);
            printf("\nInforme a senha: ");
            scanf("%d", &senhaConta);
            printf("\nInforme valor do saque: ");
            scanf("%f", &valor);
            saque(cpfConta, senhaConta, valor);
        }
    }
    return 0;
}


