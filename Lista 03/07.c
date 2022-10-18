/*
  Crie um programa para gerenciar as contas correntes dos clientes do Banco X.
  O algoritmo deverá ler, para cada cliente, o código do cliente (tipo inteiro),
  o saldo anterior (tipo real) e as movimentações da conta.

  Cada movimentação é composta por um código (inteiro, 1, 2 ou 3, indicando crédito,
  débito ou fim das movimentações deste cliente) e um valor, para as operações 1 ou 2.
  Deverá ser impresso, para cada cliente, o seu código e o saldo atual
  (após o processamento das movimentações).

  Ao final, deverá ser impresso o total de dinheiro em caixa no banco
  (soma dos saldos de todos os clientes) e o código do cliente que possui o maior saldo.
  O programa se encerra quando se digita um código de cliente com valor menor ou igual a zero.
*/

#include <stdio.h>

int main() {
  int clientCode = 1,
    clientWithMaxBalance = 1,
    option;
  float balance = 0,
    balanceHolder = 0,
    totalBalance = 0,
    maxBalance = 0;

  while (clientCode > 0) {
    printf("Digite o codigo do cliente: ");
    scanf("%d", &clientCode);

    if (clientCode <= 0) {
      break;
    }

    option = 0;

    while (option != 3) {
      printf("\n1 - Credito");
      printf("\n2 - Debito");
      printf("\n3 - Encerrar");
      printf("\n\nQual operacao? ");
      scanf("%d", &option);

      while (option < 1 || option > 3) {
        printf("Digite uma operacao valida: ");
        scanf("%d", &option);
      }

      if (option == 1) {
        printf("Digite o valor do credito: ");
        scanf("%f", &balanceHolder);
        balance += balanceHolder;
      }

      if (option == 2) {
        printf("Digite o valor do debito: ");
        scanf("%f", &balanceHolder);
        balance -= balanceHolder;
      }

      if (option == 3) {
        break;
      }
    }

    if (balance > maxBalance) {
      maxBalance = balance;
      clientWithMaxBalance = clientCode;
    }

    totalBalance += balance;

    printf("\nCodigo do cliente: %d", clientCode);
    printf("\nSaldo atual: %.2f\n\n", balance);
  }

  printf("\n\nDinheiro em caixa: %.2f", totalBalance);
  printf("\nCodigo do cliente com maior saldo: %d", clientWithMaxBalance);

  return 0;
}
