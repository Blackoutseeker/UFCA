/*
  Escreva um programa em C que realiza a soma de vários números.
  A quantidade de números a serem somados não é conhecida a priori
  e nem fornecida pelo usuário explicitamente.
  O programa deve começar lendo do usuário um número.
  Em seguida, o programa deve perguntar ao usuário se mais algum número vai ser digitado;
  se o usuário digitar 1, o programa deve ler mais um número e então novamente
  perguntar se mais algum número vai ser digitado; quando o usuário finalmente
  digitar um número diferente de 1, o programa deve imprimir na tela a soma
  de todos os números que foram digitados (não incluindo, porém, os números
  digitados como resposta à pergunta sobre se mais algum número deve ser digitado).
*/

#include <stdio.h>

int main() {
  int numberHolder = 0, totalSum = 0;

  printf("Digite um numero: ");
  scanf("%d", &numberHolder);
  totalSum += numberHolder;

  do {
    printf("Deseja somar mais um numero? ");
    printf("\n(Digite 1 caso queira): ");
    scanf("%d", &numberHolder);

    if (numberHolder != 1) {
      printf("O total da soma eh: %d", totalSum);
      return 0;
    }

    printf("Digite o numero a ser somado: ");
    scanf("%d", &numberHolder);

    totalSum += numberHolder;

  } while (numberHolder);

  return 0;
}
