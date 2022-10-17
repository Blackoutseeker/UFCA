/*
  Dado um número inteiro positivo n, calcular a soma dos
  n primeiros números inteiros positivos (sem usar a fórmula da PA).
*/

#include <stdio.h>

int main() {
  int n, holder = 0;

  printf("Digite um numero inteiro positivo: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Numero inteiro positivo invalido.");
    return -1;
  }

  for (int index = 0; index <= n; index++) {
    holder += index;
  }

  printf("A soma eh: %d", holder);

  return 0;
}
