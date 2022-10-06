/*
  Dado um natural n, faça um programa para determinar o número harmônico Hn definido como:
  Hn = (Σ, k = 1, até n; 1/k).
*/

#include <stdio.h>

int main() {
  int n;
  float Hn = 0;

  printf("Digite um numero n natural: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Numero natural invalido");
    return 0;
  }

  if (n == 0) {
    printf("Hn = 1");
    return 0;
  }

  for (int k = 1; k <= n; k++) {
    Hn += (1 / k);
  }

  printf("Hn = %.2f", Hn);

  return 0;
}
