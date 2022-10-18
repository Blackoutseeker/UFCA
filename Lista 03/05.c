/*
  Faça um programa que lê um número inteiro positivo n e imprima os valores:

    j
    ∑ i
    i=1

  para j de 1 até n, um valor por linha.
*/

#include <stdio.h>

int main() {
  int n, sum = 0;

  printf("Digite um valor inteiro positivo: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Numero inteiro positivo invalido");
    return -1;
  }

  else if(n == 0) {
    printf("A somatoria eh: 1");
    return 0;
  }

  for (int index = 1; index <= n; index++) {
    for (int j = 1; j <= index; j++) {
      sum += j;
      printf("\nSoma: %d", sum);
    }
  }

  return 0;
}
