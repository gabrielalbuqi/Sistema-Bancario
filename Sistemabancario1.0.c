#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct {
    int numero_conta;
    char nome_cliente[50];
    float saldo;
    int ativa;
} Conta;

Conta contas[MAX_CONTAS];
int total_contas = 0;

void criar_conta() {
    Conta nova_conta;
    printf("Digite o nome do cliente: ");
    scanf("%s", nova_conta.nome_cliente);
    printf("Digite o saldo inicial: ");
    scanf("%f", &nova_conta.saldo);

    if (nova_conta.saldo < 0) {
        printf("Saldo inicial invalido. O saldo inicial deve ser maior ou igual a zero.\n");
        return;
    }

    nova_conta.ativa = 1;
    nova_conta.numero_conta = total_contas + 1;
    contas[total_contas++] = nova_conta;
    printf("Conta criada com sucesso! O número da sua conta é: %d\n", nova_conta.numero_conta);
}

void realizar_transacao(int tipo) {
    int numero_conta;
    float valor;
    printf("Digite o numero da conta: ");
    scanf("%d", &numero_conta);
    printf("Digite o valor: ");
    scanf("%f", &valor);

    for (int i = 0; i < total_contas; i++) {
        if (contas[i].numero_conta == numero_conta && contas[i].ativa) {
            if (tipo == 1) {
                contas[i].saldo += valor;
                printf("Deposito realizado com sucesso! Saldo atual: %.2f\n", contas[i].saldo);
            } else if (tipo == 2) {
                if (contas[i].saldo >= valor) {
                    contas[i].saldo -= valor;
                    printf("Saque realizado com sucesso! Saldo atual: %.2f\n", contas[i].saldo);
                } else {
                    printf("Saldo insuficiente.\n");
                }
            }
            return;
        }
    }
    printf("Conta nao encontrada ou inativa.\n");
}

void depositar() {
    realizar_transacao(1);
}

void sacar() {
    realizar_transacao(2);
}

void saldo() {
    int numero_conta;
    printf("Digite o numero da conta: ");
    scanf("%d", &numero_conta);

    for (int i = 0; i < total_contas; i++) {
        if (contas[i].numero_conta == numero_conta && contas[i].ativa) {
            printf("Saldo da conta: %.2f\n", contas[i].saldo);
            return;
        }
    }
    printf("Conta não encontrada ou inativa.\n");
}

void fechar_conta() {
    int numero_conta;
    printf("Digite o numero da conta que deseja fechar: ");
    scanf("%d", &numero_conta);

    for (int i = 0; i < total_contas; i++) {
        if (contas[i].numero_conta == numero_conta && contas[i].ativa) {
            contas[i].ativa = 0;
            printf("Conta fechada com sucesso.\n");
            return;
        }
    }
    printf("Conta nao encontrada ou inativa.\n");
}

int main() {
    int opcao;
    do {
        printf("\n--------- Menu ---------\n");
        printf("1. Criar Conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Verificar Saldo\n");
        printf("5. Fechar Conta\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_conta();
                break;
            case 2:
                depositar();
                break;
            case 3:
                sacar();
                break;
            case 4:
                saldo();
                break;
            case 5:
                fechar_conta();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 6);

    return 0;
}
