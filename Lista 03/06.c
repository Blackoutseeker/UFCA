/*
  Faça um programa que leia um número inteiro n e imprima n
  linhas na tela com o seguinte formato (exemplo se n = 6):

    +
    * +
    * * +
    * * * +
    * * * * +
    * * * * * +
*/

#include <stdio.h>

int main() {
  int n;

  printf("Digite um numero inteiro positivo maior que 1: ");
  scanf("%d", &n);

  if (n <= 1) {
    printf("Numero invalido");
    return -1;
  }

  for (int col = 2; col <= n; col++) {
    if (col == 2) {
      printf("\n+\n");
    }

    for (int line = 2; line <= col; line++) {
      printf("* ");
      if (line == col) {
        printf("+\n");
      }
    }
  }

  return 0;
}
