/*
  Dadas duas sequências com n números inteiros entre 0 e 9 (cada uma em um
  vetor), calcular a sequência de números que representa a soma dos inteiros
  que estão na mesma posição.
*/

#include <stdio.h>

#define RANGE 2

int main() {
  int n1[RANGE], n2[RANGE], result[RANGE];

  for (int index = 0; index < RANGE; index++) {
    printf("Digite um numero inteiro entre 0 e 9: ");
    scanf("%d", &n1[index]);

    while (n1[index] < 0 || n1[index] > 9) {
      printf("Digite um numero inteiro valido entre 0 e 9: ");
      scanf("%d", &n1[index]);
    }

    printf("Digite um numero inteiro entre 0 e 9: ");
    scanf("%d", &n2[index]);

    while (n2[index] < 0 || n2[index] > 9) {
      printf("Digite um numero inteiro valido entre 0 e 9: ");
      scanf("%d", &n2[index]);
    }
  }

  for (int index = 0; index < RANGE; index++) {
    result[index] = n1[index] + n2[index];
  }

  for (int index = 0; index < RANGE; index++) {
    printf("\nA soma do indice %d eh: %d", index, result[index]);
  }

  return 0;
}
